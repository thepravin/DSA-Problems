
// GFG : Count the Reversals

#include <iostream>
#include <stack>
using namespace std;

int countRev(string s)
{
    // your code here

    // if string is odd
    if (s.length() % 2 != 0)
    {
        return -1;
    }

    stack<int> st;
    int count = 0;

    // chek valid paranthesis , and remove it {}
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }

    // find reversal count
    while (!st.empty())
    {
        char top = st.top();
        st.pop();

        // if top and prev char was same
        if (top == st.top())
        {
            count++;
            st.pop();
        }
        else
        {
            // top == '}' && st.top() == '{' ; different
            count += 2;
            st.pop();
        }
    }

    return count;
}

int main()
{
    string s = "{{}{{{}{{}}{{";

    cout << countRev(s) << endl;

    return 0;
}