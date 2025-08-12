// GFG : Construct Tree from Inorder & Preorder

class Solution {
public:
    unordered_map<int, int> mp;
    
    Node* constructTree(vector<int>& preorder, int s, int e, int &preIdx) {
        // Base case
        if (s > e || preIdx >= preorder.size()) return NULL;
        
        // Create the root node from preorder traversal
        Node* root = new Node(preorder[preIdx]);
        
        // Find the root index in inorder using the hashmap
        int inIdx = mp[preorder[preIdx]];
        preIdx++;  // Move to next preorder element
        
        // Recursively build left and right subtrees
        root->left = constructTree(preorder, s, inIdx - 1, preIdx);
        root->right = constructTree(preorder, inIdx + 1, e, preIdx);
        
        return root;
    }
    
    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        // Build a map of inorder values to their indices
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int preIdx = 0;  // Start from first element in preorder
        return constructTree(preorder, 0, inorder.size() - 1, preIdx);
    }
};
