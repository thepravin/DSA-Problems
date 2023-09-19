// LeetCode : 680

#include <iostream>
#include <string.h>
using namespace std;

bool checkPalindrome(string s, int star, int end)
{
    while (star <= end)
    {
        if (s[star] == s[end])
        {
            star++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool validPalindrome(string s)
{
    int i = 0;
    int j = s.length() - 1;

    while (i <= j)
    {
        if (s[i] != s[j])
        {
            // ya to i wala remove karo , ya j
            return checkPalindrome(s, i + 1, j) || checkPalindrome(s, i, j - 1);
        }
        else
        {
            // s[i]==s[j]
            i++;
            j--;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    bool ans = validPalindrome(s);

    if (ans)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}