// Give tree is level order , so print it as level order

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

void buildLevelOrderTree(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data for root" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        // Step 1 : select first root
        Node *temp = q.front();
        q.pop();

        // Step 2 : select left of root
        cout << "Enter left node for : " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new Node(leftData);
            q.push(temp->left);
        }
        // Step 3 : Select right of root
        cout << "Enter Right node for : " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new Node(rightData);
            q.push(temp->right);
        }
    }
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

    buildLevelOrderTree(root);
    // 5 4 2 -1 -1 1 -1 -1 3 -1 -1

    cout << endl;

    levelOrder(root);

    return 0;
}