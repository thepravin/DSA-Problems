#include <bits/stdc++.h>
using namespace std;

string triangleType(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    string ans;
    if (nums[0] + nums[1] > nums[2])
    {
        if (nums[0] == nums[1] && nums[0]  == nums[2])
        {
            ans = "equilateral";
                }
        else if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2])
        {
            ans = "isosceles";
        }
        else if ((nums[0] + nums[1] > nums[2]) && (nums[2] + nums[1] > nums[0]) && (nums[0] + nums[2] > nums[1]))
        {
            ans = "scalene";
        }
      
    }
    else
    {
        ans = "none";
    }

    return ans;
}

int main()
{
    vector<int> nums = {10, 9, 9};

    cout << triangleType(nums) << endl;

    return 0;
}
