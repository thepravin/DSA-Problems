// LeetCode : 1910. Remove All Occurrences of a Substring

#include <iostream>
#include <string.h>
using namespace std;

string removeOccurrences(string s, string part)
{
    int pos = s.find(part);
    while (pos != string::npos)
    {
        s.erase(pos,part.length());
        pos = s.find(part);
    }
    return s;
    
}

int main()
{
    string s;
    cin >> s;
    string part;
    cin >> part;

    string ans = removeOccurrences(s, part);
    cout << ans << endl;

    return 0;
}