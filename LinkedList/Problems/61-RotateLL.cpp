// LeetCode - 61

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// *************************************************
int listLength(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != nullptr)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
ListNode *rotateRight(ListNode *head, int k)
{
    if (!head)
        return head;

    int length = listLength(head); // find length

    // Adjust k to avoid unnecessary rotations
    k = k % length;
    if (k == 0)
        return head; // No rotation needed

    int newLastNodeInx = length - k - 1; // index of new last node

    // find new last node
    ListNode *newLastNode = head;
    while (newLastNodeInx > 0)
    {
        newLastNode = newLastNode->next;
        newLastNodeInx--;
    }
    // new head
    ListNode *newHead = newLastNode->next;

    // new tail
    newLastNode->next = nullptr;

    // connect old tail to old head
    ListNode *temp = newHead;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = head;

    // connect newhead to old head
    head = newHead;

    return head;
}

int main()
{
    int k = 2;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = rotateRight(head, k);

    // Print the rotated linked list
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
