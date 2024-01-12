#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int *arr;
    int size;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (rear == front)
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            // check if q becom empty
            if (front == rear)
            {
                front = rear = 0; // start from index '0'
            }
        }
    }

    int getFront()
    {
        if (rear == front)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool empty()
    {
        if (rear == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int getSize()
    {
        return rear-front;
    }
};

int main()
{
    Queue q(5);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
   

    cout << "Front : " << q.getFront() << endl;

    q.pop();
    cout << "Front after pop : " << q.getFront() << endl;
     q.push(6); // full
    cout<<"Size after pop : "<<q.getSize()<<endl;


    if (q.empty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is Not empty" << endl;
    }

    return 0;
}