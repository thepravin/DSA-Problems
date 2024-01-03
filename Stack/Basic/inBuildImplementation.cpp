#include <iostream>
#include <stack>
using namespace std;

int main()
{

    stack<int> st;

    // insert
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop();

    // size
    cout << "Size of Stack : " << st.size() << endl;

    // top
    cout << "Top Element : " << st.top() << endl;

    // is empty
    if (st.empty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }

    // stack Print
    cout<<"Stack Elements : ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
