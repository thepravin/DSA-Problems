// Find middle node
// LeetCode 25

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

int getLength(Node *&head)
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

// ************************************************

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empth" << endl;
        return NULL;
    }
    int len = getLength(head);
    if (k > len)
    {
        cout << "Enter valid value for k" << endl;
        return head;
    }

    // Step A : reverse first k nodes of LL
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;
    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // step B : recursive call
    if (forward!=NULL)
    {
        // we still have node left to reverse
        head->next = reverseKNodes(forward,k);
    }

    // step c : return new head
    return prev;
    
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
   Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
 

    print(head);
    cout << endl;

    head=reverseKNodes(head,3);
    print(head);
    cout << endl;

    return 0;
}