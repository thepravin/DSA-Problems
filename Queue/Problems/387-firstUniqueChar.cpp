// LeetCode -387

#include <iostream>
#include <queue>
using namespace std;

int firstUniqChar(string s)
{
    queue<char> q;
    int frq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        frq[ch - 'a']++;
        q.push(i);

        while (!q.empty())
        {
            if (frq[s[q.front()] - 'a'] > 1)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
    }

    if (q.empty())
    {
        return -1;
    }

    return q.front();
}

int main()
{
    string st = "aabb";

    cout << firstUniqChar(st);
}

/* 
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> m;

        for(int i=0;i<s.length();i++)
        // storing how many times a character appears in order
        // leetcode -> l e t c o d
        //             1 3 1 1 1 1
        // first time unique character apeared is -> l in string
          m[s[i]]++;

        // m[s[0]] -> s[0] = l and m[s[0]] =1
        // m[s[1]] -> s[1] = e and m[s[1]] =3
        // m[s[2]] -> s[2] = t and m[s[2]] =1
        // and so on
        for(int i=0;i<s.length();i++)
          {
              if(m[s[i]]==1)     
                return i;
          }
          return -1;   
    }
}; */