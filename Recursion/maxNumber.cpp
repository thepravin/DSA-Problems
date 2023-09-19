#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

void findMax(int arr[], int size, int i, int &maxi)
{
    // base case
    if (i >= size)
        return;

    // solve only first case
    if (arr[i] >= maxi)
    {
        maxi = arr[i];
    }

    // recursion call
    findMax(arr, size, i + 1, maxi);
}

int main()
{
    int arr[] = {5, 8, 9, 4, 8, 5, 6, 31};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxi = INT_MIN;
    int i = 0; // for traviling arr
    findMax(arr, size, i, maxi);
    cout << "Answer :" << maxi << endl;

    return 0;
}