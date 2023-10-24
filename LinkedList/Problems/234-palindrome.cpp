// Leetcode 234

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

Node* reverseLLLoop(Node*head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL)
    {
        Node*forwardNode = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forwardNode;
    }
    return prev;
}

bool isPalindrome(Node *&head)
{
    // find the middle node
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // reverse second part of list
      Node* secondReversePart = reverseLLLoop(slow);

    // compare first and second part
    Node*firstPart = head;
    while (secondReversePart!=NULL)
    {
       if (firstPart->data != secondReversePart->data)
       {
        return false;
       }
       firstPart=firstPart->next;
       secondReversePart=secondReversePart->next;
       
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
   // Node *third = new Node(20);
   // Node *fourth = new Node(10);
    // Node *fifth = new Node(50);

    head->next = second;
    second->next = NULL;
   // third->next = fourth;
   // fourth->next = NULL;
    // fifth->next = NULL;

    print(head);
    cout<<endl;
    bool ans = isPalindrome(head);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}