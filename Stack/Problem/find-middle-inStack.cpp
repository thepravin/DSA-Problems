// find middle element in stack

#include<iostream>
#include<stack>
using namespace std;

void middleElement(stack<int>&st, int totalSize)
{   
    if((totalSize/2)+1 == st.size()){
        cout<<"Middle Element : "<<st.top();
        return;
    }

    int temp = st.top();
    st.pop();

    // recursion
    middleElement(st,totalSize);

    //backtrack
    st.push(temp);

}

int main(){

    stack <int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    middleElement(st,st.size());

 


    return 0;
}