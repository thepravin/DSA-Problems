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

void print(Node *head)
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

    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    print(head);

    cout << endl;
    InsertAtPosition(head, tail, 30, 0);
    print(head);

    cout << endl;
    InsertAtPosition(head, tail, 40, 4);
    print(head);

    return 0;
}