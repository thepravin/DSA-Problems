// LeetCode = 17. Letter Combinations of a Phone Number

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(string digits, vector<string> &ans, int index, string output, vector<string> &mapping)
{
    // base case
    if (digits.length() <= index)
    {
        ans.push_back(output);
        return;
    }

    // 1 case
    int digit = digits[index] - '0';
    string value = mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        // include
        output.push_back(ch);
        // recursive call
        solve(digits, ans, index + 1, output, mapping);
        // backtracking
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> ans;

    if (digits.length() == 0)
    {
        return ans;
    }

    int index = 0;
    string output = "";
    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    solve(digits, ans, index, output, mapping);

    return ans;
}

int main()
{
    string digit = "23";

    vector<string> ans = letterCombinations(digit);
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}