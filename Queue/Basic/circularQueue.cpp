
#include <iostream>
using namespace std;

class CirQueue
{
public:
    int front;
    int rear;
    int size;
    int *arr;

    CirQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        // check full
        if ((front == 0 && rear == size - 1))
        {
            cout << "Queue is Full !!" << endl;
        }
        // single or first element
        else if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = data;
            rear++;
        }
        // circular nature
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
            arr[rear] = data;
            rear++;
        }
        // default case
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        // chcek empty
        if (front == -1)
        {
            cout << "Queue is Empty !!!" << endl;
        }
        // single element
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        // cicurlar nature
        else if (front == size - 1)
        {
            front = 0;
        }
        // default case
        else
        {
            front++;
        }
    }
};