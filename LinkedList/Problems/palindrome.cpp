// 1-2-3-2-1

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

Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

bool isPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty";
        return false;
    }
    if (head->next == NULL)
    {
        // only 1 node is present
        return true;
    }

    // Step A : find middle node
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    // slow point to middle node

    // Step B: reverse the second part
    Node *reverseKaHead = reverseLL(slow->next);
    // connect the reversed left part to LL
    slow->next = reverseKaHead;

    // Step C : comparing two part
    Node *tempA = head;
    Node *tempB = reverseKaHead;
    while (tempB != NULL)
    {
        if (tempA->data != tempB->data)
        {   // not palindrome
            return false;
        }
        else
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }

    return true;
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
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    print(head);
    cout << endl;

    bool ans = isPalindrome(head);

    if (ans)
    {
        cout << "Palindrome is Present";
    }
    else
    {
        cout << "Palindrome is Not Present";
    }

    return 0;
}