#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool allZeros(vector<int> &frq)
{
    for (int &num : frq)
    {
        if (num != 0)
            return false;
    }
    return true;
}

vector<int> search(string pat, string txt)
{
    int n = pat.length();
    int m = txt.length();

    vector<int> frq(26, 0);
    for (char ch : pat)
    {
        frq[ch - 'a']++;
    }

    int i = 0;
    int j = 0;
    vector<int>result;

    while (j < m)
    {
        frq[txt[j] - 'a']--;
        if ((j - i + 1) == n)
        {
            if (allZeros(frq))
            {
                result.push_back(i);
            }
            frq[txt[i] - 'a']++; // reset the frq of i char.
            i++;
        }
        j++;
    }

    return result;
}

int main()
{
   string txt = "forxxorfxdofr";
   string pat = "for";
   vector<int>ans = search(pat,txt);
   for(int&num:ans){
    cout<<num<<" ";
   }

    return 0;
}