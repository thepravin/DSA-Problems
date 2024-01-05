#include <iostream>
#include <stack>
using namespace std;

void insertBottom(stack<int> &st, int data)
{
    // base case
    if (st.size()==0)
    {
        st.push(data);
        return;
    }

    int temp = st.top();
    st.pop();

 
    insertBottom(st, data);

    st.push(temp);
}

int main()
{
    stack<int> st;
    st.push(5);
    st.push(15);
    st.push(27);
    st.push(32);

    int data = 10;
    insertBottom(st, data);

     while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}