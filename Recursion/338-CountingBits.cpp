// Leet Code 338

#include <iostream>
#include <vector>
using namespace std;

int count(int n)
{
    // base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    // process
    if (n % 2 == 0)
        return count(n / 2); // every 2 power number contain only one 1
    else
        return 1 + count(n / 2); // in 5 one is extra
}

vector<int> countBits(int n)
{
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        ans.push_back(count(i));
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> ans = countBits(n);
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}