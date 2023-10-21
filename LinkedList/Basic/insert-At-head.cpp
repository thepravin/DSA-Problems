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

void insertAtHead(Node *&head,Node*&tail, int data)
{

        if (head == NULL)
        {
            Node *newNode = new Node(data);
            head = newNode;
            tail = newNode;            
        }
        

    // Step 1 : create newNode object
    Node *newNode = new Node(data);

    // Step 2 :
    newNode->next = head;

    // Step 3 :
    head = newNode;
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

    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,10);
    insertAtHead(head,tail,20);
    insertAtHead(head,tail,30);
    insertAtHead(head,tail,40);

    print(head);

    return 0;
}