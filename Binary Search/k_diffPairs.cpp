// Leet Code - 532

// Method = 1
#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <set>       // set
#include <utility>   // pair
using namespace std;

/*
int searchPairs(vector<int> arr, int k)
{
    // sort array
    sort(arr.begin(), arr.end());

    // store unique pairs
    set<pair<int, int>> ans;

    int i = 0;
    int j = 1;
    while (j < arr.size())
    {
        int diff = arr[j] - arr[i];

        if (diff == k)
        {
            ans.insert({arr[i], arr[j]});
            i++;
            j++;
        }
        else if (diff > k)
        {
            i++;
        }
        else
        {
            j++;
        }

        if (i == j)
        {
            j++;
        }
    }
    return ans.size();
}

int main()
{
    vector<int> arr{3, 1, 4, 1, 5};
    int k = 2;

    int ans = searchPairs(arr, k);

    cout << "Total Pairs Diff is " << k << " Are : " << ans << endl;

    return 0;
}

*/

// method 2 -> Binary Search
int binarySearch(vector<int>arr,int start ,int x)
    {
        int e = arr.size()-1;
        int mid = start+(e-start)/2;

        while(start<=e){
            if(arr[mid] == x){
                return mid;
            }else if(arr[mid]>x){
                e=mid-1;
            }else{
                start=mid+1;
            }
            mid = start+(e-start)/2;
        }
        return -1;
    }

 int findPairs(vector<int>& nums, int k)
     {
            sort(nums.begin(),nums.end());
            set<pair<int,int>> ans;
    for(int i=0;i<nums.size();i++)
    {
        if(binarySearch(nums,i+1,nums[i]+k) != -1)
        {
            ans.insert({nums[i],nums[i]+k});
        }
    }

    return ans.size();
    }

    int main(){
        vector<int>arr{3,1,4,1,5};
        int k=2;

        int ans = findPairs(arr,k);

        cout << "Total Pairs Diff is " << k << " Are : " << ans << endl;

    return 0;

    }