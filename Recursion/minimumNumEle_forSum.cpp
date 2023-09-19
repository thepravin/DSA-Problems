// you have to tell minimum number of element required to reach target sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int solve(vector<int>& arr,int target)
{
    // base case
    if(target == 0) return 0;

    if(target <0) return INT_MAX;

    // process
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solve(arr,target-arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini,ans+1);
        }
        
    }
    return mini;
    
}

int main()
{
    vector<int>arr {1,2};
    int target = 3;

    int ans = solve(arr,target);
    cout<<ans<<endl;
   

    return 0;
}