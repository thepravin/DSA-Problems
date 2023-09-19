// LeetCode : 242

#include <iostream>
#include <string>
#include<algorithm>
using namespace std;

// Approach 1
int charSum(string a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i];
    }
    return sum;
}

/*
// Approach 2
// O(n+m+256)=O(n+m)

bool isAnagram(string s, string t)
{
    int frqTable[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        frqTable[s[i]]++;
    } // O(n)
    for (int i = 0; i < t.size(); i++)
    {
        frqTable[t[i]]--;
    } // O(m)

    for (int i = 0; i < 256; i++)
    {
        if (frqTable[i] != 0)
        {
            return false;
        }
    } // O(256)
    return true;
} */

// App 3
bool sortString(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    if (s.length()!=t.length())
    {
        return false;
    }

    for (int i = 0; i < s.length();)
    {
        if (s[i]==t[i])
        {
            i++;
        }else{
            return false;
        }
        
    }
    return true;
    
}

int main()
{
    string s = "ac";
    string t = "bb";

    bool ans = sortString(s, t);
    if (ans)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    /*   int sSum = charSum(s);
        int tSum = charSum(t);

        if (sSum == tSum )
        {
            cout<<"True"<<endl;
        }else{
            cout<<"False"<<endl;
        } */

    /*  bool ans = isAnagram(s, t);
     if (ans)
     {
         cout << "True" << endl;
     }
     else
     {
         cout << "False" << endl;
     } */
}