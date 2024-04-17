#include <iostream>
#include <queue>
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
// ------------------------------------- TAKE INPUT IN BST ------------------
Node* insertNode(Node *root, int data)
{
    // first node
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // not first node
    if (root->data > data)
    {
        // left side
        root->left = insertNode(root->left, data);
    }
    else
    {
        // right side
        root->right = insertNode(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertNode(root, data);
        cin >> data;
    }
}

// --------------------------------- LEVEL ORDER PRINTING ------------------
void printBST(Node *root)
{
    queue<Node *> q;
    q.push(root);

    // level seperator
    q.push(NULL);

    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";

            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for Node" << endl;
    takeInput(root);
    cout << "Print BST" << endl;
    printBST(root);
}