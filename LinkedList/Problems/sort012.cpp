// sort 0 1 2

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

void sortZeroOneTwo(Node *&head)
{
    // Step 1 : count
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeros++;
        else if (temp->data == 1)
            ones++;
        else if (temp->data == 2)
            twos++;

        temp = temp->next;
    }

    // Step 2 : Print in original LL
    temp = head;
    while (zeros--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (ones--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (twos--)
    {
        temp->data = 2;
        temp = temp->next;
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

    Node *head = new Node(1);
    Node *second = new Node(1);
    Node *third = new Node(2);
    Node *fourth = new Node(2);
    Node *fifth = new Node(0);
    Node *six = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = six;
    print(head);
    cout << endl;

    sortZeroOneTwo(head);
    print(head);

    return 0;
}