
// Reverse First k elements in queue

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reversefirstK(queue<int> &q, int &k)
{
    stack<int> st;

    // step 1: push queue to stack 'k' elements
    int kElement=0;
    while (kElement<k)
    {
        int element = q.front();
        q.pop();
        st.push(element);
        kElement++;
    }

    // step 2: push stack to queue
    while (!st.empty())
    {
        int element = st.top();
        st.pop();
        q.push(element);
    }

    // step 3 : psuh {(size-k) to last} element after the k reverse element,
    // because here : 2 1 3 4 5
    int size = q.size();
    int count = size - k;
    while (count > 0)
    {
        int element = q.front();
        q.pop();
        q.push(element);
        count--;
    }
}

int main()
{
    queue<int> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);
    // 5 4 3 2 1

    int k = 3;

    reversefirstK(q, k);

    while (!q.empty())
    {
        cout << q.front() << " "; // 3 4 5 2 1
        q.pop();
    }
}