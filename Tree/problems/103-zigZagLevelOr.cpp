 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(root == nullptr){
        return {};
    }

    queue<TreeNode*> q;
    q.push(root);

    vector<vector<int>> result;
    bool leftToRight = true;

    while(!q.empty()){
        vector<int> temp;
        int size = q.size();

        // level process
        for(int i = 0; i < size; i++){
            TreeNode* frontNode = q.front();
            q.pop();

            // Ensure temp vector is resized to accommodate current index
            if (leftToRight)
                temp.push_back(frontNode->val); // Insert at the end for left to right
            else
                temp.insert(temp.begin(), frontNode->val); // Insert at the beginning for right to left

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }

        // direction change
        leftToRight = !leftToRight;

        result.push_back(temp);
    }

    return result;
}