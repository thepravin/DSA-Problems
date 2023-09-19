#include <iostream>
using namespace std;

int partition(int arr[],int s, int e)
{
    // Step 1: choose pivote elemetn
    int pivotIndex = s;
    int pivotElement = arr[s];

    // Step 2: find right position for pivot element and place it there position
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }

    // jab main loop se bhahar hua,toh mere pivot ki right position
    // ka index ready h
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

    // Step 3: left me chote and right me bade
    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivotElement)
        {
            i++;
        }
        while (arr[j] > pivotElement)
        {
            j--;
        }

        // 2 case ho sakte h -:
        // A = you found the element to swap
        // B = no need to swap
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition logic,return pivotIndex
    int p = partition(arr, s, e);

    // recursive calls
    //  pivot element ->left
    quickSort(arr, s, p - 1);
    // pivot element ->right
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {1,1,1,1,1,1,1,1,12,2,22,2,2,2, 1, 5, 6, 8, 4, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}