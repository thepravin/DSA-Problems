#include <iostream>
using namespace std;

class Stack
{
    int size;

public:
    int *arr;
    int top;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "Stack Overflow !!!" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow !!!" << endl;
            return;
        }

        top--;
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty !!!" << endl;
        }
        return arr[top];
    }

    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        int n = top + 1;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    st.pop();
    cout << st.getTop() << endl;
    cout << st.isEmpty() << endl;
    cout << st.getSize() << endl;
    st.pop();
    st.pop();
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();

    return 0;
}