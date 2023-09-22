// LeetCode 392 - is Subsequence

#include <iostream>
#include <string.h>
using namespace std;

bool solve(string &s, int i, string &t, int j)
{
    // base case
    if (i == s.length())
    {
        return true;
    }
    if (j == t.length())
    {
        return false;
    }

    // 1 case
    if (s[i] == t[j])
    {
        return solve(s, i + 1, t, j + 1);
    }
    else
    {
       return solve(s, i, t, j + 1);
    }
}

bool isSubsequence(string s, string t)
{
    int i = 0;
    int j = 0;
    return solve(s, i, t, j);
}

int main()
{
    string s = "b";
    string t = "ahbgdc";

    bool ans = isSubsequence(s, t);

    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}