#include <iostream>
#include <stack>
using namespace std;
//************************************************

void insertStack(stack<int>&st,int target){
    // base case
    if(st.empty()){
        st.push(target);
        return;
    }

    if (st.top()>=target)
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();

    insertStack(st,target);

    // back tracking
    st.push(topElement);
    
}

void sortStack(stack<int>&st){
    // base case 
    if(st.empty()){
        return;
    }

    int target = st.top();
    st.pop();
    cout<<target<<endl;

    sortStack(st);

    insertStack(st,target);
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
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(42);

    print(st);
    cout<<endl;
    sortStack(st);
    print(st);

    return 0;
}