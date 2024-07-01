// GFG : https://www.geeksforgeeks.org/problems/make-binary-tree

#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        this->data = data;
        left=NULL;
        right=NULL;
    }
};


// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    // 1. In level order use queue
   queue<TreeNode *>q;
   root = new TreeNode(head->data);
   q.push(root);
   head=head->next;
   
   // 2. travel list
   while(head){
       // 3. pop front or root
       TreeNode * parent = q.front();
       q.pop();
       
       // 4. create left and right nodes
       TreeNode * leftChild = NULL;
       TreeNode * rightChild = NULL;
       
       // 5. Assine leftChild and rightChild values
       leftChild = new TreeNode(head->data);
       q.push(leftChild);
       head=head->next;
       if(head){
           rightChild = new TreeNode(head->data);
           q.push(rightChild);
           head=head->next;
       }
       // 6. assine parents left and right
       parent->left = leftChild;
       parent->right = rightChild;
       
   }
}
