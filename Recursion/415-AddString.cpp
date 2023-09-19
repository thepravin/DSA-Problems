// LeetCode 415

#include <iostream>
#include <string.h>
#include<algorithm> // string reverse
using namespace std;

void addRE(string &num1, int p1, string &num2, int p2, int charry, string &ans)
{
    // base case
    if (p1 < 0 && p2 < 0)
    {
        if (charry != 0)
        {
            ans.push_back(charry + '0');
        }
        return;
    }

    // ek case solve
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0'; // char to int
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int sum = n1 + n2 + charry;
    int digit = sum % 10;
    charry = sum / 10;
    ans.push_back(digit+'0');

    addRE(num1, p1 - 1, num2, p2 - 1, charry, ans);
}

string addStrings(string num1, string num2)
{
    string ans = "";
    int p1 = num1.size() - 1;
    int p2 = num2.size() - 1;
    int charry = 0;
    addRE(num1, p1, num2, p2, charry, ans);
    // because of push back ans is reverse
    reverse(ans.begin(),ans.end());

    return ans;
}

int main()
{

    string num1;
    cin >> num1;
    string num2;
    cin >> num2;

    string ans = addStrings(num1, num2);
    cout << ans << endl;
}