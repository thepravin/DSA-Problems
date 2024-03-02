
/*

T.C = O(N^2)

int height(Node*root){
    if(root == NULL) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    int ans = max(leftHeight , rightHeight)+1;

    return ans;
}

int diameter(Node* root){
    if(root = NULL) return 0;

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right)+1;

    int ans = max(op1,max(op2,op3));

    return ans;
}


*/

/*

T.C = O(N)



pair<int, int>
fastDiametr(TreeNode<int> *root) { // first = diameter second = height
  if (root == NULL) {
    pair<int, int> p = make_pair(0, 0);
    return p;
  }

  pair<int, int> left = fastDiametr(root->left);
  pair<int, int> right = fastDiametr(root->right);

  int op1 = left.first;
  int op2 = right.first;
  int op3 = left.second + right.second;

  pair<int, int> ans;
  ans.first = max(op1, max(op2, op3));
  ans.second = max(left.second, right.second) + 1;

  return ans;
}

int diameterOfBinaryTree(TreeNode<int> *root) {
  // Write Your Code Here.
  return fastDiametr(root).first;
}



*/