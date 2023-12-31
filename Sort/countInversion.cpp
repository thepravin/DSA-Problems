// hackerank = https://www.hackerrank.com/challenges/ctci-merge-sort/problem

#include <iostream>
#include <string>
#include <vector>
using namespace std;

long merge(vector<int> &arr, vector<int> &temp, int start, int mid, int end)
{
    int i = start, j = mid + 1, k = start;
    long c = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            // arr[i]>arr[j] inversion count case;
            temp[k] = arr[j];
            k++;
            j++;
            c += mid - i + 1;
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    // temp into original arr
    while (start <= end)
    {
        arr[start] = temp[start];
        start++;
    }
    return c;
}

long mergeSort(vector<int> &arr, vector<int> &temp, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    int mid = start + (end - start) / 2;
    long c = 0;

    c += mergeSort(arr, temp, start, mid);
    c += mergeSort(arr, temp, mid + 1, end);
    c += merge(arr, temp, start, mid, end);

    return c;
}

long countInversions(vector<int> &arr)
{
    long c = 0; // inversion counting
    vector<int> temp(arr.size(), 0);
    c = mergeSort(arr, temp, 0, arr.size() - 1);

    return c;
}

int main()
{
    vector<int> arr{8, 4, 2, 1};

    long ans = countInversions(arr);

    cout << ans << endl;
    
    for(auto i:arr){
        cout<<i<<" ";
    }

    return 0;
}