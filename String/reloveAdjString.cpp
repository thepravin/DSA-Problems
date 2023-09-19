// LeetCode : 1047. Remove All Adjacent Duplicates In String

#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    string ans = " ";

    for (int i = 0; i < s.length(); i++)
    {
        int end = ans.length() - 1;
        int first = ans.length();

        if (first > 0)
        {
            if (s[i] != ans[end])
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }

        else
        {
            ans.push_back(s[i]);
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;

    string ans = removeDuplicates(s);
    cout << ans << endl;

    return 0;
}