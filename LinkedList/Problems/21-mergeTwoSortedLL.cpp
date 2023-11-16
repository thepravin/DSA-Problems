// Leet Code = 21

// Find middle ListNode

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


ListNode* mergeTwoList(ListNode*list1,ListNode*list2){
    // creating dummy node
    ListNode* mptrHead = new ListNode(-1);
    ListNode* mptrTail = mptrHead;
    // two pointer for traveling two LL
    ListNode* left = list1;
    ListNode* right =list2;

    while (left!=NULL && right!= NULL)
    {
        if (left->val <= right->val)
        {
            mptrTail->next = left;
            mptrTail = left;
            left=left->next;
        }else{
            mptrTail->next =right;
            mptrTail=right;
            right=right->next;
        }
        
    }

    // if one LL reach to null
    if (left==NULL)
    {
        mptrTail->next = right;
    }else{
        mptrTail->next=left;
    }

    // removing -1 from LL
    mptrHead =mptrHead->next;

    return mptrHead;
    
    

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
    head->next = second;
    second->next = third;
   
    ListNode*head2 = new ListNode(2);
    ListNode*second2 = new ListNode(4);
    ListNode*third2 = new ListNode(5);
    head2->next=second2;
    second2->next=third2;

    print(head);
    cout<<endl;
    print(head2);
    cout<<endl;

    ListNode* ans = mergeTwoList(head,head2);
    print(ans);

    return 0;
}