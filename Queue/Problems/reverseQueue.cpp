
// Reverse Queue

/*
    Approach 1 :
        - using stack
        - pop in queue and push in stack  ; O(n)
        -then pop in stack and push in queue  ; O(n)
            T.C = 2*O(n)=O(n)
            S.C = O(n) = creating stack

    Approach 2 : using recursion
        - save first element
        -use recursion on remaning element
        -here call stack was created
        -i.e stack top was 1 and bottom was 5
        -similar as arrroach 1
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Approach 1:
void reverseQueue_1(queue<int> &q)
{
    stack<int> st;

    // Step 1: push into stack from queue
    while (!q.empty())
    {
        int element = q.front();
        q.pop();

        st.push(element);
    }

    // Step 2: push into queue from stack
    while (!st.empty())
    {
        int element = st.top();
        st.pop();

        q.push(element);
    }
}

// Approach 2 : using recursion

void usingRecursion(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    int element = q.front();
    q.pop();

    usingRecursion(q);

    q.push(element);
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

    //  reverseQueue_1(q);
    usingRecursion(q);

    while (!q.empty())
    {
        cout << q.front() << " "; // 1 2 3 4 5
        q.pop();
    }
}