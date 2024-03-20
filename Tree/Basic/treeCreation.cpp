
// Tree Cretion

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// use recursion

Node *buildTree(Node *root)
{

    // creating one node
    int data;
    cout << "Enter Data :" << endl;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        return NULL;
    }

    // left
    cout << "Enter LEFT node of " << data << endl;
    root->left = buildTree(root->left);

    // righ
    cout << "Enter RIGHT node of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    return 0;
}



/*
Node* helper(Node*root,vector<int>&arr,int index){

    if(index>=arr.size()|| arr[index]==-1){
        return nullptr;
    }

    root = new Node(arr[index]);

    root->left = helper(root, arr, 2*index+1);
    root->right = helper(root, arr, 2*index+2);

    return root;
   
}

Node* createTree(vector<int>&arr){
    // Write your code here.

    Node* root = NULL;
    
    root = helper(root,arr,0);

    return root;

}


*/