
// return index of last occurance of char
#include <iostream>
using namespace std;

/*
    // for left to right search

void findPosi(string&s,char&ch,int i,int&ans)
{
    //base case
    if(i>=s.size())
    {
        return;
    }

    // ek case solutioj
    if(s[i]==ch) ans =i;

    //recursion
    findPosi(s,ch,i+1,ans);
}

int main()
{
    string str="abbcdbe";
    char ch='b';
    int ans =0;
    int i=0;
   findPosi(str,ch,i,ans);
    cout<<ans;
    return 0;
} */

// right to left
void findPosi(string &s, char &ch, int i, int &ans)
{
    // base case
    if (i<0)  // <----- chage
    {
        return;
    }

    // ek case solutioj
    if (s[i] == ch)
    {
        ans = i;
        return;  // <----- chage
    }

    // recursion
    findPosi(s, ch, i - 1, ans);
}

int main()
{
    string str = "abbcdbe";
    char ch = 'b';
    int ans = 0;
    int i = str.size()-1;  // <----- chage
    findPosi(str, ch, i, ans);
    cout << ans;
    return 0;
}