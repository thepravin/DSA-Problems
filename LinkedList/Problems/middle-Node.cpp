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

Node *getMiddle(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return head;
    }
    if (head->next == NULL)
    {
        // only 1 node present
        return head;
    }

    // LL have >1 node

    Node *slow = head;
    Node *fast = head; // fast = head->next  // depend on which answer you want in even node case

    while (slow != NULL && fast != NULL)
    {
        fast = fast->next; // 1 step

        // now check fast next is null or not
        if (fast != NULL)
        {
            fast = fast->next; // 2 step
            slow = slow->next; // 1 step
        }
    }

    return slow;
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

    cout << getMiddle(head)->data << endl;

    return 0;
}