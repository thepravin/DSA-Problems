
// LeetCode 32

#include <iostream>
#include <stack>
using namespace std;

//******************** without stack ***************************
int longestValidParentheses2(string s)
{

    int count = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i - 1] == '(' && s[i] == ')')
        {
            count++;
        }
        else
        {
            continue;
        }
    }

    return count * 2;
}

//**************************** with stack **************************

int longestValidParentheses(string s)
{
    int MaxLength = 0;
    stack<int> st;
    st.push(-1); // for calculating length

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (st.empty())
            {
                st.push(i);
            }
            else
            {
               int length = i - (st.top());
               MaxLength = max(length,MaxLength);
            }
        }
    }
    return MaxLength;
}

int main()
{
    string s = ")))))()()";

    // cout << longestValidParentheses2(s) << endl;
    cout << longestValidParentheses(s) << endl;

    return 0;
}
