// maximum sum of non adjecent element

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void solve(vector<int> &arr, int i, int CurrSum, int &maxi)
{
    // base case
    if (i >= arr.size())
    {
       
        maxi = max(maxi, CurrSum);
        return;
    }

    // include
    solve(arr, i + 2, CurrSum + arr[i], maxi);
   
    // exclude
    solve(arr, i + 1, CurrSum, maxi);
}

int main()
{
    vector<int> arr{1,3,2,1};
    int i = 0;
    int maxi = INT_MIN;
    int CurrSum = 0;

   solve(arr, i, CurrSum, maxi);

    cout << maxi << endl;

    return 0;
}