// First negative in every k window

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void firstNegative(vector<int> &v, int &n, int &k)
{
    deque<int> dq;

    // step 1 : process first window
    for (int i = 0; i < k; i++)
    {
        if (v[i] < 0)
        {
            dq.push_back(i); // store -ve number index
        }
    }

    // step 2 : remaning window processing
    for (int i = k; i < n; i++)
    {
        // purani window ka answer
        if (dq.empty())
        {
            cout << 0 << " ";
        }
        else
        {
            cout << v[dq.front()] << " ";
        }
        // step 3: remove outoff window element ( remove first and add k+1)
        while ((!dq.empty()) && (i - dq.front() >= k))
        {
            dq.pop_front();
        }
        // add
        if (v[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // step 4: handel last window
    if (dq.empty())
    {
        cout << 0 << " ";
    }
    else
    {
        cout << v[dq.front()] << " ";
    }
}

int main()
{
    vector<int> v = {12, -1, -7, 8, -15, 30, 16, 28};
    int size = v.size();
    int k = 3;

    firstNegative(v, size, k);
}