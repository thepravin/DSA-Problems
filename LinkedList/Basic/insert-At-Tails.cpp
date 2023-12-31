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

    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,40);
    insertedAtTails(head, tail, 30);
   insertedAtTails(head,tail,50);

    print(head);

    return 0;
}