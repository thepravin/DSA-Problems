
// In place merge

// method 1 : Gap Method

// ceil(n+m/2) give upper bond => 2.5 -> 3 or second method given in inplacemerge code gap=

// s.c = > O(nlog n) without using extra array

#include <iostream>
#include <vector>
using namespace std;

void inPlaceMerge(vector<int> &v, int start, int mid, int end)
{
    int total_len = end - start + 1;
    int gap = total_len / 2 + total_len % 2;
    while (gap > 0)
    {
        int i = start, j = start + gap;

        while (j <= end)
        {
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
            }
            i++;
            j++;
        }

        gap = gap <= 1 ? 0 : gap / 2 + gap % 2;
    }
}

void mergeSort(vector<int> &v, int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = start + end >> 1;

    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    inPlaceMerge(v, start, mid, end);
}

/* vector<int> sortArray(vector<int> &arr)
{
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
} */

int main()
{
    vector<int> arr{2, 4, 8, 9, 1};

    // vector<int> ans = sortArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
}