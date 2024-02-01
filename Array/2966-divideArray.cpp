
// LeetCode - 2966  : Divide Array Into Arrays With Max Difference.

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


vector<vector<int>> divideArray(vector<int> &nums, int k) {
    // Sort the given array
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    // Iterate through the sorted array with a step of 3
    for (int i = 2; i < nums.size(); i += 3) {
        // Check if the difference between the third and first element in the triplet is less than or equal to 'k'
        if (nums[i] - nums[i - 2] <= k) {
            ans.push_back({nums[i - 2], nums[i - 1], nums[i]});
        }
    }

    // Check if the size of the resulting 2D vector is equal to the size of the input array
    if (nums.size() != ans.size() * ans[0].size()) {
        // If not, return an empty 2D vector
        return {};
    } else {
        return ans;
    }
}


int main()
{
   /*  vector<int> v = {1, 3, 4, 8, 7, 9, 3, 5, 1};
    int k = 2; */
    
    vector<int> v = {1,3,3,2,7,3};
    int k = 3;

    vector<vector<int>> ans = divideArray(v, k);

  // Print the 2D vector
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[0].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl; // Move to the next line after each row
    }
}
