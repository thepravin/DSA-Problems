// find starting node of loop

/*
 * always consider secial case : if cycle start from first node. at that time slow and fast both point to head, if
 * both are moving then by one then they never meet. [soconsider second code always......]
 */

/*
* ========> SECOND CODE <=========
// Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        Node*slow = head;
        Node*fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                break;
            }
        }


    // If no loop is found, return
    if (slow != head) {
        return;
    }

    // special : If loop start form first node
    if(fast==head){
        while(fast->next != slow){
            fast = fast->next;
        }
        fast->next=NULL;
    }else{
         Node*prev = fast;
            while(slow!=fast){
                prev = fast;
                slow=slow->next;
                fast=fast->next;
            }
            prev->next=NULL;
    }
    return;

    }

 */

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
Node *removeLoop(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            // they meet then
            slow = head;
            break;
        }
    }

    // crete one previous pointer behind the fast pointer
    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL;
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
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eighth = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eighth;
    eighth->next = ninth;
    ninth->next = eighth;

    removeLoop(head);
    print(head);

    return 0;
}