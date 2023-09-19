// Used for finding prime numbers

#include <iostream>
#include <vector>
using namespace std;

/* vector<bool> Sieve(int n)
{
    vector<bool>sieve(n+1 , true);

    sieve[0]=sieve[1]=false;

    for (int i = 2; i <= n; i++)
    {
        if (sieve[i]==true)
        {
            int j=i*2;
            while (j<=n)
            {
                sieve[j]=false;
                j+=i;
            }

        }

    }
    return sieve;

} */

vector<bool> Sieve(int n)
{
    vector<bool> sieve(n + 1, true);

    sieve[0] = sieve[1] = false;

    for (int i = 2;  i*i <=n  /*i <= n */; i++)  // Optimisation 2:Outter loop
    {
        if (sieve[i] == true)
        {
            int j = i * i; // Optimisation 1: inner Loop
                           // first unmarked number would be i*i, as other have been marked
                           //  by 2 to (i-1)
            while (j <= n)
            {
                sieve[j] = false;
                j += i;
            }
        }
    }
    return sieve;
}

int main()
{
    int n;
    cin >> n;

    vector<bool> ans = Sieve(n);

    for (int i = 0; i < n; i++)
    {
        if (ans[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}