
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

void levelOrder(Node *root)
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
        { // pura level traverse ho chuka hai
            cout << endl;

            if (!q.empty())
            {
                // abbhi element bache hai
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

    root = buildTree(root);
    // 5 4 2 -1 -1 1 -1 -1 3 -1 -1

    cout<<endl;

    levelOrder(root);

    return 0;
}