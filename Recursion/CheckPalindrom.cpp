#include <iostream>
using namespace std;

bool checkPalRE(string&str,int start,int end)
{
    // base case
    if(start>=end){
        return true;
    }

    // ek case
    if(str[start]!=str[end]) return false;

    //RE
    checkPalRE(str,start+1,end-1);
}

int main()
{
    string str;
    cin >> str;

    bool ans = checkPalRE(str, 0, str.size() - 1);

    if (ans)
        cout << "True";
    else
        cout << "False";

    return 0;
}