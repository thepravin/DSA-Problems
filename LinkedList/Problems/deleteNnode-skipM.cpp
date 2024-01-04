// delete N nodes after skipping M nodes

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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

//****************** GfG  *************************
void linkdelete(Node *head, int M, int N)
{
    if (!head)
        return;

    Node *it = head;
    for (int i = 0; i < M - 1; ++i)
    {
        if (!it)
        {
            return;
        }
        it = it->next;
    }
    if (!it)
    {
        return;
    }

    Node *MthNode = it;
    it = MthNode->next;
    for (int i = 0; i < N; ++i)
    {
        if (!it)
        {
            break;
        }

        Node *temp = it->next;
        delete it;
        it = temp;
    }

    MthNode->next = it;

    linkdelete(it, M, N);
}
//**************************************************
//****************** code studio  *************************

Node *helper(Node *head, int n, int m)
{
    Node *it = head;

    for (int i = 0; i < m - 1; ++i)
    {
        if (!it || !it->next)
        {
            return head; // Return the current head if unable to reach Mth node
        }
        it = it->next;
    }

    Node *MthNode = it;
    it = MthNode->next;
    for (int i = 0; i < n && it; ++i)
    {
        Node *temp = it->next;
        delete it; // Free the memory
        it = temp;
    }

    MthNode->next = it;

    if (it)
    {
        // If there are more nodes, make a recursive call
        helper(it, n, m);
    }

    return head; // Return the new head after deletion
}

Node *getListAfterDeleteOperation(Node *head, int N, int M)
{
    if (!head)
    {
        return head;
    }

    head = helper(head, N, M);
    return head;
}
//**************************************************

int main()
{
    Node *head = new Node(19);
    Node *first = new Node(1);
    Node *second = new Node(3);
    Node *third = new Node(5);
    Node *fourth = new Node(9);
    Node *fifth = new Node(4);
    Node *sixth = new Node(10);
    Node *seventh = new Node(1);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    int M = 2;
    int N = 1;

    printLL(head);
    cout << endl;

    // linkdelete(head, M, N);

    head = getListAfterDeleteOperation(head, N, M);

    printLL(head);

    return 0;
}