
// Interleave first and second half of the queue

#include <iostream>
#include <queue>
using namespace std;

void interLeave(queue<int> &q)
{
    // step 1 : create new queue for first half
    queue<int> temp;
    int size = q.size();
    int i = 0;
    while (i < (size / 2))
    {
        int element = q.front();
        q.pop();
        temp.push(element);
        i++;
    }
    // Step 2 : mapping
    while (!temp.empty())
    {
        int first = temp.front();
        temp.pop();
        int second = q.front();
        q.pop();
        q.push(first);
        q.push(second);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interLeave(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}