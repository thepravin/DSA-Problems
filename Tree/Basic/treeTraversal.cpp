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

// **************************************************************

/*
    Always see function name, copy function code but see function name
*/

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // step 1 : go last left node
    inorderTraversal(root->left);

    // step 2 : if last node emplty then,function return
    cout << root->data << " ";

    // step 3 : go right
    inorderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // step 1 : go last left node
    postOrderTraversal(root->left);

    // step 2 : go right
    postOrderTraversal(root->right);

    // step 3 : if last node emplty then,function return
    cout << root->data << " ";
}

void pretOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // step 1 : print node
    cout << root->data << " ";

    // step 2 : go  left
    pretOrderTraversal(root->left);

    // step 3 : go right
    pretOrderTraversal(root->right);
}

// **************************************************************

int main()
{
    Node *root = NULL;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    cout << "Inorder Traversal : " << endl;
    inorderTraversal(root);
    cout << endl;
    cout << "Postorder Traversal : " << endl;
    postOrderTraversal(root);
    cout << endl;
    cout << "Preorder Traversal : " << endl;
    pretOrderTraversal(root);

    return 0;
}