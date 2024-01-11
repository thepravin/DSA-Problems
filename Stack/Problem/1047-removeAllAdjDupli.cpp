// LeetCode 1047- Remove all adjacent duplicats in string

#include <iostream>
#include <stack>
#include <algorithm> 
using namespace std;

string removeDuplicates(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        if (!st.empty() && st.top() == ch)
        {
            // remove
            st.pop();
        }else{
            st.push(ch);
        }

        
    }

    // stack to string
    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // reverse for correct ans
    reverse(ans.begin(),ans.end());

    return ans;
    
}

int main()
{
    string s = "abbaca";

    string ans = removeDuplicates(s);

    cout << ans << endl;

    return 0;
}