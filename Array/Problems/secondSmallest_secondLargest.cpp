#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {6,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int firstSmall = INT_MAX;
    int firstLarger = INT_MIN;
    int secondSmall = INT_MAX;
    int secondLarger = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < firstSmall)
        {
            secondSmall = firstSmall;
            firstSmall = arr[i];
        }
        else if (arr[i] < secondSmall)
        {
            secondSmall = arr[i];
        }
        if (arr[i] > firstLarger)
        {
            secondLarger = firstLarger;
            firstLarger = arr[i];
        }
        else if (arr[i] > secondLarger)
        {
            secondLarger = arr[i];
        }
    }

    cout << "Second small : " << secondSmall << endl;
    cout << "Second Larger : " << secondLarger << endl;

    return 0;
}