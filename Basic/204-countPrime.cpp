// LeetCode : 204
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

// timeComplxicity O(n^2) = o(n)*O(n);


bool isPrime(int i)
{
    if (i <= 1)
        return false;

    for (int j = 2; j < i; j++)
    {
        if ((i % j) == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) // O(n)
    {
        if (isPrime(i)) // O(n)
        {
            count++;
        }
    }
    return count;
}

*/

int countPrimes(int n)
{
    if(n==0) return 0;
    int count = 0;
    vector<bool> prime(n, true); // all n are allready prime.

    prime[0] = prime[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            count++;

            int j = 2 * i;
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }

    return count;
}

int mian()
{
    int n;
    cin >> n;

    int ans = countPrimes(n);
    cout << ans << endl;

   
}