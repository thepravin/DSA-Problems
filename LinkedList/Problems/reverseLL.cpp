#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Distructor for delete node
    ~Node()
    {
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1 : create newNode object
    Node *newNode = new Node(data);

    // Step 2 :
    newNode->next = head;

    // Step 3 :
    head = newNode;
}

void insertedAtTails(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1 : create newNode object
    Node *newNode = new Node(data);

    // Step 2 : connect tail with new node
    tail->next = newNode;

    // Step 3 : update tail
    tail = newNode;
}

// find Length of LL

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

// insert at position
void InsertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    int length = findLength(head);

    if (pos == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    if (pos >= length)
    {

        insertedAtTails(head, tail, data);

        return;
    }

    // Step 1 :  find previous and current position
    Node *previous = head;
    int i = 0;
    while (i < pos)
    {
        previous = previous->next;
        i++;
    }
    Node *curr = previous->next;

    // Step 2 : create new node
    Node *newNode = new Node(data);

    // Step 3 :
    newNode->next = curr;

    // Step 4 :
    previous->next = newNode;
}

// ***************** Delete ****************

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete , LL is empty";
        return;
    }

    int length = findLength(head);

    // first
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    // last
    if (position == length)
    {
        // step 1 : find previous
        Node *prev = head;
        int i = 1;
        while (i < position - 1) // second last node
        {
            prev = prev->next;
            i++;
        }
        // step 2 :
        prev->next = NULL;
        // step 3 :
        Node *temp = tail;
        // step 4:
        tail = prev;
        // step 5
        delete temp;
        return;
    }

    // deleting middle node
    // step 1: find previous and current
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step 2:
    prev->next = curr->next;
    // step 3;
    curr->next = NULL;
    // step 4;
    delete curr;
    return;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// ****************** Reverse LL *******************

Node* reverseLL(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        // LL reverse ho chuki hai
        // return new head
        return prev;
    }

    // 1 case
    Node *forword = curr->next;
    curr->next = prev;

    reverseLL(curr, forword);
}

Node* reverseLLLoop(Node*head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL)
    {
        Node*forwardNode = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forwardNode;
    }
    return prev;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    InsertAtPosition(head, tail, 30, 0);
    InsertAtPosition(head, tail, 40, 4);
    print(head);
    cout << endl;

    // Reverse LL code
    Node *prev = NULL;
    Node *curr = head;
  //  head = reverseLL(prev, curr);
  head = reverseLLLoop(head);
    print(head);

    return 0;
}