// gfg

/*

T.C = O(N^2)

// approach 1
 int height(Node*root){
        if(root == NULL) return 0;

        int left = height(root->left);
        int right = height(root->right);

        int ans = max(left , right)+1;

        return ans;
    }

    bool isBalanced(Node *root)
    {
        //  Your Code here
        // base case
        if(root == NULL) return true;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff =abs(height(root->left)-height(root->right)) <=1 ; // given condition

        if(left&&right&&diff){
            return true;
        }else{
            return false;
        }


    T.C = O(n^2)
     pair<bool,int> isBalancedFast(Node*root){
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        
        pair<bool,int>leftAns = isBalancedFast(root->left);
        pair<bool,int>rightAns = isBalancedFast(root->right);
        
        bool left = leftAns.first;
        bool right = rightAns.first;
        
        bool diff = abs(leftAns.second - rightAns.second)<=1;
        
        pair<bool,int>ans;
        ans.second=max(leftAns.second,rightAns.second)+1;
        if(left&&right&&diff){
            ans.first = true;
        }else{
            ans.first = false;
        }
        
        return ans;
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
       return isBalancedFast(root).first;
    }    

*/