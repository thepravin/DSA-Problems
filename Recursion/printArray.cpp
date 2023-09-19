#include <iostream>
using namespace std;

// without Index
/* void printArray(int arr[], int size)
{
    if (size == 0)
        return;

    cout << *arr << " ";
    printArray(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    printArray(arr, size);

    return 0;
} */

// Using Index
void printArray(int arr[], int size, int i)
{
    if (i >= size)
        return;

    cout << arr[i] << " ";
    printArray(arr, size, i + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = 5;
    int i = 0; // index
    printArray(arr, size, i);

    return 0;
}