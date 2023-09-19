// LeetCode : 345

#include <iostream>
#include <string>
#include <algorithm>
#include<cctype>//tlower
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch); // conver upper to lower
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string s)
{
    int start = 0;
    int end = s.size() - 1;
   while (start<=end)  
    {
        if (isVowel(s[start]) && isVowel(s[end]))
        {
            swap(s[start], s[end]);
            start++;
            end--;
        }
        else if (!isVowel(s[start]))
        {
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

    string ans = reverseVowels(s);
    cout << ans << endl;

    return 0;
}