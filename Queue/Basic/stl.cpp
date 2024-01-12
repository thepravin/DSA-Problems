
#include<iostream>
#include<queue>
using namespace std;


int main()
{
    queue<int> q;

    q.push(50);
    q.push(4);
    q.push(3);
    q.push(5);
    q.push(2);

    cout<<"Size : "<<q.size()<<endl;
    
    q.pop(); // 50 fifo
    cout<<"Size : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"queue is empty"<<endl;
    }else{
        cout<<"not empty"<<endl;
    }


    // front element
    cout<<"Front element "<<q.front()<<endl;
  
    

    return 0;
}