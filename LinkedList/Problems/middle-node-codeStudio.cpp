// code studio

// Find middle node

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// ************************************************

int LLlength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *findMiddle(Node *head)
{
    // Write your code here
    Node *temp = head;
    int length = LLlength(head);
    cout<<length%2<<endl;
    int middel = 0;

    // length is even
    if (length % 2 == 0)
    {
        middel = (length + 1)/2;
    }
    else
    {
        middel = length/2;
    }

    while (middel--)
    {
        temp = temp->next;
    }

    return temp;
}

// *********************************************

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

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);
    cout << endl;

    cout << findMiddle(head)->data << endl;

    return 0;
}