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
Node *insertNode(Node *root, int data)
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

//------------------------------------- find element present or not ----------------
// every node was unique
Node *isTargetPresent(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    // check
    if (root->data == target)
        return root;

    if (root->data > target)
    {
        return isTargetPresent(root->left, target);
    }
    else
    {
        return isTargetPresent(root->right, target);
    }
}
//--------------------------- MIN , MAX ------------------------------
int minVal(Node *root)
{
    if (root == NULL)
        return -1;

    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node *root)
{
    if (root == NULL)
        return -1;

    Node *temp = root;
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}
//-------------------------------------- DELETE NODE------------------
Node *deleteNode(Node *root, int target)
{
    if (root == NULL)
        return root;

    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            // node is leaf
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *rightSubTree = root->right;
            delete root;
            return rightSubTree;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            Node *leftSubTree = root->left;
            delete root;
            return leftSubTree;
        }
        else
        {
            // left and right preset
            // 1. find predeccssor
            int inorderPre = maxVal(root->left);
            // 2. set it to root node
            root->data = inorderPre;
            // 3. delete old node from left subtree
            root->left = deleteNode(root->left, inorderPre);
            return root;
        }
    }

    else if(root->data > target){
        root->left = deleteNode(root->left,target);
    }
    else{
        root->right = deleteNode(root->right,target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter data for Node" << endl;
    takeInput(root);

    cout << "Print BST" << endl;
    printBST(root);

    cout << "Enter Delete Node : ";
    int deleteN;
    cin >> deleteN;
    deleteNode(root, deleteN);

    cout << "Print BST" << endl;
    printBST(root);

    // cout << "Enter Target" << endl;
    // int target;
    // cin >> target;
    // bool ans = isTargetPresent(root, target);
    // if (ans)
    //     cout << "Present" << endl;
    // else
    //     cout << "Not Present" << endl;

    // cout<<"MIN Number : "<<minVal(root)<<endl;
    // cout<<"MAX Number : "<<maxVal(root)<<endl;
}