// LeetCode : 205

#include <iostream>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0};           // mapping of each cahr of s to t
    bool isTcharMapped[256] = {0}; // store if t[i] char already mapped with s[i]

    // mapping
    for (int i = 0; i < s.size(); i++)
    {
        // if char of string s is not present present in map and char of string t not present in set(no duplicate) then we assign and insert in set to no further duplicate
        if (hash[s[i]] == 0 && isTcharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            isTcharMapped[t[i]] = true;
        }
    }

    // checking
    for (int i = 0; i < s.size(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;

    bool ans = isIsomorphic(s, t);

    if (ans)
    {
        cout << "Ture" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}