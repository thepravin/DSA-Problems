// LeetCode 1291 : Sequential Digits

#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    vector<int> ans;

    // Step 1: Create queu and store 1 to 9
    queue<int>q;
    for (int i = 1; i < 9; i++)
    {
        q.push(i);
    }

    // Step 2: incrasing it
    while (!q.empty())
    {
        int num = q.front();
        q.pop();
       

        if (num>=low && num<=high)
        {
            ans.push_back(num);
        }

        if (num > high)
        {
            break;
        }
        
        // last digit < 9
        if (num%10 <9)
        {
            int rem = num%10;

            num = num*10 + rem +1;  // if num=123 then 1230 + 3 + 1 => 1234
            q.push(num);
        }
        
        
    }
    
    

    return ans;
    
    
}

int main()
{
    int low = 100;
    int high = 300;

    vector<int> ans = sequentialDigits(low, high);

    for (auto i : ans)
    {
        cout << i << " ";
    }
}