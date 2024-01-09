
//  Smaller Elements

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Next Smaller Elements
vector<int> nextSmallerElements(vector<int> v)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--) // right to left
    {
        int curr = v[i];

        // check curr element with stack top
        while (st.top() >= curr)
        {
            st.pop();
        }
        // chota element mil gaya
        ans[i] = st.top();

        // push curr in stack at any condition
        st.push(curr);
    }
    return ans;
}

// Previous smaller
vector<int> previousSmaller(vector<int> input)
{
    vector<int> ans(input.size());
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < input.size(); i++) // left to right
    {
        int curr = input[i];

        while (st.top() >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> v = {2, 1, 4, 3};

    // vector<int>ans = nextSmallerElements(v);
    vector<int> ans = previousSmaller(v);

    // print
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}