// LeetCode : 647. Palindromic Substrings

#include <iostream>
#include <string>
using namespace std;

int expandAroundIndex(string s, int i , int j)
{
    int count = 0;
    while (i>=0 && j<s.length() && s[i]==s[j])
    {
        i--;
        j++;
        count++;
    }
    return count++;
    
}

int countSubstrings(string s)
{
    int count = 0;
    int n = s.length();
    for (int  = 0; i < n; i++)
    {
        // odd
        int countOdd = expandAroundIndex(s, i, i);
        count = count + countOdd;

        // even
        int countEven = expandAroundIndex(s, i, i + 1);
        count = count + countEven;
    }
    return count;
}

int main()
{
    string s;
    cin >> s;

    int ans = countSubstrings(s);
    cout << ans << endl;
}