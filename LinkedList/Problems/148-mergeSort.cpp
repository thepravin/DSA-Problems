// Leet code = 148 = sort LL using merge sort

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// ************************************************

ListNode *mergeTwoList(ListNode *list1, ListNode *list2)
{
    
    // creating dummy node
    ListNode *mptrHead = new ListNode(-1);
    ListNode *mptrTail = mptrHead;
    // two pointer for traveling two LL
    ListNode *left = list1;
    ListNode *right = list2;

    while (left != NULL && right != NULL)
    {
        if (left->val <= right->val)
        {
            mptrTail->next = left;
            mptrTail = left;
            left = left->next;
        }
        else
        {
            mptrTail->next = right;
            mptrTail = right;
            right = right->next;
        }
    }

    // if one LL reach to null
    if (left == NULL)
    {
        mptrTail->next = right;
    }
    else
    {
        mptrTail->next = left;
    }

    // removing -1 from LL
    mptrHead = mptrHead->next;

    return mptrHead;
}

ListNode* middleNode(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}

ListNode *sortList(ListNode *head)
{   // base case: empty list or list with one node
        if (!head || !head->next) {
            return head;
        }

    // find middle of LL and divide two LL
    ListNode* middle = middleNode(head);
    ListNode* left = head;
    ListNode* right = middle->next;
    middle->next=0;

    // using recursion 
    left = sortList(left); 
    right=sortList(right);

    // merge
    ListNode* mergeLL = mergeTwoList(left,right);

    return mergeLL;


}

// *********************************************

void print(ListNode *&head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{

    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(3);
    ListNode *third = new ListNode(5);
    ListNode *foruth = new ListNode(2);
    ListNode *fifth = new ListNode(1);
    head->next = second;
    second->next = third;
    third->next = foruth;
    foruth->next = fifth;

    print(head);
    cout << endl;

    ListNode *ans = sortList(head);
    print(ans);

    return 0;
}