
// LeetCode - 1019 : Next greater node in LL , using stack

#include <iostream>
#include <stack>
#include <vector>
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
//*******************************************************************************



vector<int> nextLargerNodes(ListNode *head)
{
    if (head == nullptr)
    {
        //  linked list is empty
        return {};
    }

    // list into array
    vector<int> ll ;
    while (head)
    {
        ll.push_back(head->val);
        head=head->next;
    }

    stack<int>st;  // store index
 
    for (int i = 0; i < ll.size(); i++)
    {
        while (!st.empty()&& ll[i]>ll[st.top()])
        {
            // i'th element is nextLargest element, of present element index in stack
            int prev = st.top(); // store index
            st.pop(); 
            ll[prev]=ll[i];
        }
        st.push(i);
        
    }
    
    // some greate elemets are remaning
    while (!st.empty())
    {
        ll[st.top()]=0;
        st.pop();
    }

    // last elements is always 0
    ll[ll.size()-1]=0;

    return ll;
    
    
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *first = new ListNode(7);
    ListNode *second = new ListNode(5);
    ListNode *third = new ListNode(1);
    ListNode *fourth = new ListNode(9);
    ListNode *fifth = new ListNode(2);
    ListNode *sixth = new ListNode(5);
    ListNode *seventh = new ListNode(1);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    vector<int> ans = nextLargerNodes(head);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}