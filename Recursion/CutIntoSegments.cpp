// you have n meter rod and you have to cut into length of x,y,z meter
// and return maximum pices of rod

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN;
    // process
    int ansX = solve(n - x, x, y, z) + 1;
    int ansY = solve(n - y, x, y, z) + 1;
    int ansZ = solve(n - z, x, y, z) + 1;

    return max(ansX, max(ansY, ansZ));
}

int main()
{
    int n = 7;
    int x = 5;
    int y = 2;
    int z = 2;

    int ans = solve(n, x, y, z);

    if (ans < 0)
    {
        ans = 0;
        cout << ans << endl;
    }
    else
    {
        cout << ans << endl;
    }

    return 0;
}