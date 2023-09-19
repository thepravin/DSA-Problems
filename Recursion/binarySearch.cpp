#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int &target)
{
    // base case
    // case 1 : target not found
    if (start > end)
    {
        return -1;
    }
    // case 2 : target found
    int mid = (start + end) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }


    // arr[mid]<target -> right search
    if (arr[mid]<target)
    {
        return binarySearch(arr,mid+1,end,target);
    }
    // arr[mid]>target -> left search
    if (arr[mid]>target)
    {
        return binarySearch(arr,start,mid-1,target);
    }
    
}

int main()
{
    vector<int> arr{10, 11, 12, 13, 14};
    int target = 1;
    int size = arr.size();
    int start = 0;
    int end = size - 1;

    int ans = binarySearch(arr, start, end, target);
    cout << "Answer is : " << ans << endl;

    return 0;
}