
// 100215 : Number of changing the key

#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int countKeyChanges(string s)
{

    stack<char> st;
    st.push(s[0]);
    int keyChange = 0;

    for (int i = 1; i < s.length(); i++)
    {
        char ch = tolower(s[i]); // current char

        if (tolower(st.top()) != ch)
        {
            st.pop();
            keyChange++;
        }
        st.push(ch);
    }

    return keyChange;
}

int main()
{
    string str = "AaCc";

    int ans = countKeyChanges(str);
    cout << ans << endl;
}