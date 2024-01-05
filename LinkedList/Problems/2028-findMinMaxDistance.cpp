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

// *********************** My logic **************************
int listLength(ListNode *head)
{
    ListNode *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

vector<int> MYLogic(ListNode *head)
{
    // ans vector
    vector<int> ans;

    if (!head || !head->next || !head->next->next)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    // store cricitcal point
    vector<int> cp;

    ListNode *temp = head->next;
    ListNode *prev = head;
    ListNode *nextNode = temp->next;
    int length = listLength(head); // list length

    while (temp != NULL && temp->next != NULL && nextNode != NULL)
    {
        if ((temp->val < prev->val) && (temp->val < nextNode->val))
        {
            int newLength = length - listLength(temp); // current node index
            cp.push_back(newLength);
        }
        else if ((temp->val > prev->val) && (temp->val > nextNode->val))
        {
            int newLength = length - listLength(temp);
            cp.push_back(newLength);
        }

        prev = temp;
        temp = nextNode;
        nextNode = nextNode->next;
    }

    if (cp.empty())
    {
        ans.push_back(-1);
        ans.push_back(-1);
    }
    else
    {
        int max = cp[cp.size() - 1] - cp[0]; // last elemtn - first element

        int min = INT_MAX;
        for (int i = 0; i < cp.size() - 1; i++)
        {
            int newCal = cp[i + 1] - cp[i];
            if (newCal < min)
            {
                min = newCal;
            }
            else
            {
                continue;
            }
        }

        ans.push_back(min);
        ans.push_back(max);
    }

    return ans;
}
//************************************************************************

// ****************************************************

vector<int> nodesBetweenCriticalPoints(ListNode *head)
{
    vector<int> ans = {-1, -1};
    ListNode *prev = head;
    if (!prev)
        return ans;
    ListNode *curr = head->next;
    if (!curr)
        return ans;
    ListNode *nxt = head->next->next;
    if (!nxt)
        return ans;

    int firstCp = -1;
    int lastCp = -1;
    int i = 1; // for tracking index;
    int minDist = INT_MAX;
    while (nxt)
    {
        bool isCP = ((curr->val < prev->val && curr->val < nxt->val) ||
                     (curr->val > prev->val && curr->val > nxt->val))
                        ? true
                        : false;

        if (isCP && firstCp == -1)
        {
            // curr is cp and it is first
            firstCp = i;
            lastCp = i;
        }
        else if (isCP)
        {
            // other than first cp
            minDist = min(minDist, i - lastCp);
            lastCp = i;
        }
        ++i;
        prev = prev->next;
        curr = curr->next;
        nxt = nxt->next;
    }

    if (firstCp == lastCp)
    {
        return ans;
        // only one cp is present
    }
    else
    {
        ans[0] = minDist;
        ans[1] = lastCp - firstCp;
    }

    return ans;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *first = new ListNode(3);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(2);
    ListNode *fourth = new ListNode(3);
    ListNode *fifth = new ListNode(2);
    ListNode *sixth = new ListNode(2);
    ListNode *seventh = new ListNode(2);
    ListNode *eight = new ListNode(7);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    // vector<int> ans = MYLogic(head);

    vector<int> ans = nodesBetweenCriticalPoints(head);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
