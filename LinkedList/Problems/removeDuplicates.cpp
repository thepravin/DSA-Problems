// 1 2 2 3 4 4
// 1 2 3 4

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

void removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is Empty";
        return;
    }
    if (head->next == nullptr)
    {
        return;
    }

    Node *curr = head;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        { // equal
            Node *temp = curr->next;
            curr->next = curr->next->next;

            // delete node
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }
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
    Node *second = new Node(10);
    Node *third = new Node(10);
    Node *fourth = new Node(10);
    Node *fifth = new Node(10);
    Node *six = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    print(head);
    cout << endl;

    removeDuplicates(head);
    print(head);

    return 0;
}