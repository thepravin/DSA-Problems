#include <iostream>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        arr = new int[size];
        this->size=size;
        top = -1;
    }

    // function

    void push(int data)
    {
        if (size - top >= 1)
        {
            // space available
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
        if (top != -1)
        {
            top--;
        }
        else
        {
            cout << "Stack Underflow !!!" << endl;
        }
    }
    int getTop()
    {
        if (top != -1)
        {
            return arr[top];
        }
        else
        {
            cout<<"Stack was Empty !!! "<<endl;
        }
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
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack st(6);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    cout << "Size of Stack : " << st.getSize() << endl;

    cout << "Top of Stack : " << st.getTop() << endl;

    if (st.isEmpty() == true)
    {
        cout << "Stack was empty" << endl;
    }
    else
    {
        cout << "Stack was not Empty" << endl;
    }

    cout << "Stack Elements : ";
    while (!st.isEmpty())
    {
        cout << st.getTop() << " ";
        st.pop();
    }

    return 0;
}