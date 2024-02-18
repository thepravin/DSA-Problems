
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