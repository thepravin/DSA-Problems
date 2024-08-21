#include <iostream>
#include <vector>
using namespace std;

/*
    T. C  = O( N )
    S. C  = O( 1 ) 
*/

int fibonacci(int n)
{   
    int prev1 = 0;
    int prev2 = 1;

   
    for (int i = 2; i <=n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    
    return prev2;
}

int main()
{
    int n;
    cout << "Enter n = ";
    cin >> n;

    if(n==0)return n;

   
    cout << fibonacci(n) << endl;

    return 0;
}
