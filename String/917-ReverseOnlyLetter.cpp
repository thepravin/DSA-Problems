// LeetCode - 917

#include <iostream>
#include <string>
#include <algorithm>
#include <ctype.h> // isalpha()
using namespace std;

string reverseOnlyLetters(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (isalpha(s[start]) && isalpha(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (!isalpha(s[start]))
        {   // run when start is not alphabet
            start++;
        }
        else
        {
            end--;
        }
    }

    return s;
}

int main()
{
    string s;
    cin >> s;
    string ans = reverseOnlyLetters(s);
    cout << ans << endl;

    return 0;
}