// Addition of two LL

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

Node *reverseLL(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *forwardNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forwardNode;
    }
    return prev;
}

Node *addition(Node *head1, Node *head2)
{
    // reverse LL
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    // addition
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    int carry = 0;
    while (head1 != NULL && head2 != NULL)
    {
        int sum = head1->data + head2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        // new node for digit
        Node *newNode = new Node(digit);

        // attachment of digit into ans
        if (ansHead == NULL)
        {
            // newNode is first node
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    while (head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
        head2 = head2->next;
    }

    // carry is remaning
    while (carry != 0)
    {
        int sum = carry;
        int digit = sum % 10;
        carry = sum / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = newNode;
    }

    // reverse ans
    ansHead = reverseLL(ansHead);

    return ansHead;
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

    Node *head1 = new Node(2);
    Node *second = new Node(4);
    // Node *third = new Node(8);
    head1->next = second;
    // second->next=third;

    Node *head2 = new Node(2);
    Node *second2 = new Node(3);
    Node *third2 = new Node(4);
    head2->next = second2;
    second2->next = third2;

    cout << "First LL : ";
    print(head1);
    cout << endl;

    cout << "Second LL : ";
    print(head2);
    cout << endl;

    Node *ans = addition(head1, head2);
    print(ans);

    return 0;
}