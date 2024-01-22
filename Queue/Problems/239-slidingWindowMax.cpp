
// LeetCode 239

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    for (int i = 0; i < k; i++)
    {
        // chota element remove karo
        while ((!dq.empty())&& nums[i]>=nums[dq.back()])
        {
            dq.pop_back(); // dq is in decreasing oreder , so front is large then next element is small..
        }

        dq.push_back(i); 
        
    }

      // first windo ka answer , alway front is large
      ans.push_back(nums[dq.front()]);
   

    for (int i = k; i < nums.size(); i++)
    {
       
        if ((!dq.empty()) && (i - dq.front() >= k)) // yaha par galti hogi
        {
            dq.pop_front();
        }

        // add
        // chota element remove karo
        while ((!dq.empty())&& nums[i]>=nums[dq.back()])
        {
            dq.pop_back(); // dq is in decreasing oreder , so front is large then next element is small..
        }

        dq.push_back(i); 


        // ans store 
        ans.push_back(nums[dq.front()]);
    }



    return ans;
}

int main()
{
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(nums, k);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}