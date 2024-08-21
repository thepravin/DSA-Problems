#include <iostream>
#include <vector>
using namespace std;

/*
    T. C  = O( N )
    S. C  = O( N ) 
*/

int fibonacci(int n, vector<int> &dp)
{   
    // step 2 ==>  base case
    dp[0]=0;
    dp[1]=1;

    // step 3 ==>  
    for (int i = 2; i <=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter n = ";
    cin >> n;

    vector<int> dp(n + 1); // step 1 ==> Initialize the dp array after reading n
    cout << fibonacci(n, dp) << endl;

    return 0;
}
