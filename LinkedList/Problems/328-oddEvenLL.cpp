
// LeetCode 328 - Odd Even Linked List

#include <iostream>
#include <vector>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
    ListNode(){
        this->val=0;
        this->next=nullptr;
    }
};

ListNode *oddEvenList(ListNode *head)
{
    ListNode* list1 = new ListNode();
    ListNode* list2 = new ListNode();
    ListNode*temp1=list1;
    ListNode*temp2=list2;
    ListNode* temp=head;
    int i=1;  
    while (temp!=nullptr)
    {
        int element = temp->val;
        if (i%2 == 1)
        {
            // odd
            ListNode* newNode = new ListNode(element);
            temp1->next=newNode;
            temp1=newNode;
            temp=temp->next;
            i++;
        }else{
            //even
             ListNode* newNode = new ListNode(element);
            temp2->next=newNode;
            temp2=newNode;
            temp=temp->next;
            i++;
        }
        
    }

  temp1->next=list2->next;


    return list1->next; 


}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *first = new ListNode(2);
    ListNode *second = new ListNode(3);
    ListNode *third = new ListNode(4);
    ListNode *fourth = new ListNode(5);
    ListNode *fifth = new ListNode(6);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    print(head);

    head = oddEvenList(head);

    cout<<endl;

    print(head);

    return 0;
}