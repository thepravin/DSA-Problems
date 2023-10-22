#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
    }
};

int getLength(Node *head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

// ************** Insertions **********************

void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1
    Node *newNode = new Node(data);

    // Step 2
    newNode->next = head;
    head->prev = newNode;

    // Step 3
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 1
    Node *newnode = new Node(data);

    // Step 2
    newnode->prev = tail;
    tail->next = newnode;

    // Step 3
    tail = newnode;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int length = getLength(head);
    if (pos >= length)
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert at meddle

    // Step 1 :
    Node *newNode = new Node(data);

    // Step 2
    Node *prevNode = head;
    int i = 1;
    while (i < pos - 1)
    {
        prevNode = prevNode->next;
        i++;
    }
    Node *currNode = prevNode->next;

    // step 3
    newNode->next = currNode;
    currNode->prev = newNode;
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

// ************** Deletion **********************

void deleteATHead(Node *&head, Node *&tail)
{
    // Step 1
    Node *temp = head;

    // step 2
    head = head->next;

    // step 3
    head->prev = NULL;
    temp->next = NULL;

    // step 4
    delete temp;
}

void deleteTail(Node *&head, Node *&tail)
{
    // step 1
    Node *temp = tail;

    // Step 2
    tail = tail->prev;

    // step 3
    tail->next = NULL;
    temp->prev = NULL;

    // step 4;
    delete temp;
}

void deleteATPosition(Node *&head, Node *&tail, int pos)
{
    if (pos == 1)
    {
        deleteATHead(head, tail);
        return;
    }
    int length = getLength(head);
    if (pos >= length)
    {
        deleteTail(head, tail);
        return;
    }

    // step 1
  Node* left = head;
  int i =1;
  while (i<pos-1)
  {
    left = left->next;
    i++;
  }
  Node*curr = left->next;
  Node*right = curr->next;

    // step 2
    left->next = right;  

    // step 3
    right->prev = left;
 

    // step 4
    curr->next = NULL;
    curr->prev = NULL;

    delete curr;
}

//********************************************************************
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    insertAtHead(head, tail, 14);
    insertAtHead(head, tail, 16);
    insertAtTail(head, tail, 50);
    insertAtPosition(head, tail, 2, 15);
    insertAtPosition(head, tail, 1, 115);
    print(head);
    cout << endl;

    // deleteATHead(head, tail);
    // deleteTail(head,tail);
    deleteATPosition(head, tail, 5);
    print(head);

    return 0;
}