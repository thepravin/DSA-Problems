// LeetCode 2181 - Merge Nodes in Between Zeros

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

// *********************** My logic **************************

ListNode *helper(ListNode *head)
{
    ListNode *temp = head;
    ListNode *newHead = NULL;
    ListNode *newTail = NULL;

    while (temp != NULL)
    {
        if (temp->val == 0)
        {
            temp = temp->next;
            continue;
        }

        ListNode *sumNode = new ListNode(0);
        while (temp != NULL && temp->val != 0)
        {
            sumNode->val += temp->val;
            temp = temp->next;
        }

        if (newHead == NULL)
        {
            newHead = sumNode;
            newTail = sumNode;
        }
        else
        {
            newTail->next = sumNode;
            newTail = sumNode;
        }
    }

    return newHead;
}

ListNode *mergeNodes(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    head = helper(head);

    return head;
}

//*************************************************************

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *first = new ListNode(3);
    ListNode *second = new ListNode(1);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(4);
    ListNode *fifth = new ListNode(5);
    ListNode *sixth = new ListNode(2);
    ListNode *seventh = new ListNode(0);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    print(head);
    cout << endl;

    ListNode *ans = mergeNodes(head);

    print(ans);

    return 0;
}
