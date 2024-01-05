#include <iostream>
#include <stack>
using namespace std;
//************************************************

void insertAtBottom(stack<int> &st, int data)
{
    // base case
    if (st.size() == 0)
    {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();

    
    insertAtBottom(st, data);

    st.push(temp);
}

void reverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int target = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, target);
}

//*********************************************
void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{

    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(27);
    st.push(32);

    print(st);
    cout<<endl;
    reverseStack(st);
    print(st);

    return 0;
}