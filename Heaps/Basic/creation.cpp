#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[101];
    int size;

    Heap()
    {
        size = 0;
    }

    void insert(int value)
    {

        // 1. add value at end of array
        size = size + 1;
        int index = size;
        arr[index] = value;

        // 2. iss value ko sahi jagah pr set karo
        while (index > 1) // array start from 1 index
        {
            int parentIndex = index / 2;
            if (arr[index] > arr[parentIndex])
            {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else
            {
                break;
            }
        }
    }

    int deleteRoot()
    {
        // replace root node value with last node
        arr[1] = arr[size];
        size--; // remove last node (delete)

        // place root node ka data on its correct position
        int index = 1;
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            int largest = index;

            // --> find larget node from left and right child
            if (left < size && arr[largest] < arr[left])
            {
                largest = left;
            }
            if (right < size && arr[largest] < arr[right])
            {
                largest = right;
            }

            // --> arrage it
            if (largest == index)
            {
                // value at correct position
                break;
            }
            else
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }

        int ans = arr[1]; // max value of heap
        return ans;
    }
};

int main()
{
    Heap h;
    h.arr[0] = -1;
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;

    h.size = 5;

    cout << "Printing the heap : " << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }

    // insert
    h.insert(110);

    cout << endl
         << "After Insertion :" << endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout << h.arr[i] << " ";
    }
}