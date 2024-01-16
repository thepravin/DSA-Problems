
// Doubly ended queue using stl

#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);  //  10 5 20 30

    cout<<"Size : "<<dq.size()<<endl; // 4

    dq.pop_front(); //10
    dq.pop_back(); // 30

    cout<<"Size : "<<dq.size()<<endl; // 2  // 5 20

    cout<<"Front : "<<dq.front()<<endl; // 5
    cout<<"Rear : "<<dq.back()<<endl; // 20


    return 0;
}