// LeetCode
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int climbStairs(int n)
{
    // base case
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return (climbStairs(n - 1) + climbStairs(n - 2));
}

int main()
{
    int n;
    cout << "Enter Number of Staris : ";
    cin >> n;

    int ans = climbStairs(n);
    cout << "Total ways : " << ans << endl;

    return 0;
}