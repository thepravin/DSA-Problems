// HackerRank problem
#include <sstream>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> parseInts(string str)
{
    // Complete this function
    vector<int> ans;
    char ch;
    int n;
    stringstream ss(str);

    while (ss)
    {
        if (ss.peek() != ',')
        {
            if (ss >> n)
            {
                ans.push_back(n);
            }
        }
        else
        {
            ss >> ch;
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str; // 24,8,9,6
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}