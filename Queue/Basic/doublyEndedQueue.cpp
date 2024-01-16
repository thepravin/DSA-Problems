
// Doubly ended queue

#include <iostream>
using namespace std;

class DeQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    DeQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushRear(int data)
    {
        // check full
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full !!" << endl;
            return;
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

    void pushFront(int data)
    {
        // check full
        if ((front == 0 && rear == size - 1) || (front == rear + 1))
        {
            cout << "Queue is Full !!" << endl;
            return;
        }
        // single or first element
        else if (front == -1)
        {
            front = rear = 0;
        }
        // circular nature
        else if (front == 0 && rear != size - 1)
        {
            front = size - 1;
        }
        // default case
        else
        {
            front--;
        }
        arr[front] = data;
    }
    void popFront()
    {
        // chcek empty
        if (front == -1)
        {
            cout << "Queue is Empty !!!" << endl;
            return;
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
    void popRear()
    {
        // chcek empty
        if (front == -1 && rear == -1)
        {
            cout << "Queue is Empty !!!" << endl;
            return;
        }
        // single element
        else if (front == rear)
        {
            arr[front] = -1;
            front = rear = -1;
        }
        // cicurlar nature
        else if (rear == 0)
        {
            rear = size - 1;
        }
        // default case
        else
        {
            rear--;
        }
    }
};

int main()
{
    DeQueue dq(4);

    dq.pushFront(5);
    dq.pushFront(10);
    dq.pushRear(20);
    dq.pushRear(30);

   

    return 0;
}