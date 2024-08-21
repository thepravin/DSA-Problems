#include <iostream>
#include <vector>
using namespace std;

/*
    T. C  = O( N )
    S. C  = O( 2N ) ==> vector + recursion
*/

int fibonacci(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;

    // step 3 ==>  Check if value is already computed
    if (dp[n] != -1)
        return dp[n];

    // step 2 ==>  Compute and store the value
    dp[n] = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n = ";
    cin >> n;

    vector<int> dp(n + 1, -1); // step 1 ==> Initialize the dp array after reading n
    cout << fibonacci(n, dp) << endl;

    return 0;
}
