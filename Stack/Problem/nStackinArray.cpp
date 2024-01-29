// N stack in array

#include <iostream>
using namespace std;

class NStack
{
    int *a;
    int *top;
    int *next;
    int n;        // nu. of stack
    int size;     // size of main array
    int freeSpot; // free space index in main array

public:
    NStack(int n, int s) : n(n), size(s)
    {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // last element
    }

    // push x into Mth stack
    bool push(int x, int m)
    {
        if (freeSpot == -1)
        {
            return false; // stack overflow = no space to insert
        }

        // 1. fint index
        int index = freeSpot;

        // 2. update freespot
        freeSpot = next[index];

        // 3. insert in array
        a[index] = x;

        // 4.update next
        next[index] = top[m - 1];

        // 5.update top
        top[m - 1] = index;

        return true; // push successful
    }

    // pop form mth stack
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return -1; // stack underflow = no element in stack
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        int poppedElement = a[index];

        next[index] = freeSpot;

        freeSpot = index;

        return poppedElement;
    }

    ~NStack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main()
{
    NStack s(3, 6); // 3 stack , 6 size of array

    // 1 - push success , 0 - not success
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(8, 1) << endl;
    cout << s.push(9, 1) << endl;
    cout << s.push(10, 1) << endl;
    cout << s.push(11, 1) << endl;
    cout << s.push(12, 1) << endl;
    cout << s.pop(1) << endl;
}