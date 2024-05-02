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

// -------------------------------- Using Inorder ----------------------

// T.C = O(n); every nod take O(1)* n

Node *bstUsingInorder(int inorder[], int start, int end)
{
    // base case
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = bstUsingInorder(inorder, start, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, end);

    return root;
}

// ------------------- convert BST into DOUBLY LINKED LIST -----------------

void convertBstIntoDLL(Node* root ,  Node*&head){
    // base case
    if(root==NULL) return ;

    // right subtree into LL
    convertBstIntoDLL(root->right,head);

            // atach root  node
             root->right = head;

            if(head != NULL) head->left = root;

            // update head
            head = root;

    // left subtree lL
    convertBstIntoDLL(root->left,head);


}

//--------------- Doubly LL into BST ---------------

Node* doublyLLIntoBST(Node* head,int n){
    // base case
    if(head == NULL || n<=0) return NULL;

    Node* leftSubTree = doublyLLIntoBST(head , n-1-(1/2));

    Node* root = head;
    root->left = leftSubTree;

    head=head->right; // yaha par galti hogi

    // right part
    Node* rightSubTree = doublyLLIntoBST(head,n/2);

    return root;
}



//-------------------------------------------------------------------
void printLL (Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->right;
    }
    
}

int main()
{
    cout<<"BST From inorder : - " <<endl;
    int inorder[] = {2, 3, 4, 5, 6, 7, 8};
    int end = (sizeof(inorder) / sizeof(inorder[0])) - 1;
    Node *root = bstUsingInorder(inorder, 0, end);
    printBST(root);

    // ----------------------------------------

    cout<<"Convert BST INTO Doubly LL :- "<<endl;
    Node* head = NULL;
    convertBstIntoDLL(root,head);
    printLL(head);

    return 0;
}