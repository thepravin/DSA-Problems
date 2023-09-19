// 647 => 6 4 7
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void findDigits(int &n)
{
    // base case
    if (n == 0)
    {
        return;
    }
    
    // recursion
    int num = n / 10;
    findDigits(num);

    // solve 1 case
    int digit = n % 10;
    cout << digit << " ";
}

int main()
{
    int n;
    cin >> n;

    findDigits(n);

    return 0;
}