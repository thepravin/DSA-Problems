#include <bits/stdc++.h>
using namespace std;

// count prefix sum
void countPrefixSum(vector<long> &prevSum, vector<int> &nums) {
  int n = nums.size();

  prevSum[0] = nums[0];

  for (int i = 1; i < n; ++i) {
    prevSum[i] = prevSum[i - 1] + nums[i];
  }
}

// binary search to find max frq elements
int binarySearch(int target_id, int k, vector<long> &prevSum,
                 vector<int> &nums) {
  int l = 0;
  int r = target_id;
  int result = -1;

  while (l <= r) {
    int mid = l + (r - l) / 2;
    long windowElementsCount = target_id - mid + 1;
    long expectedWindowSum = windowElementsCount * nums[target_id];
    long currWindowSum = prevSum[target_id] - prevSum[mid] + nums[mid];

    int operations = expectedWindowSum - currWindowSum;

    if (operations <= k) { // need more size window
      result = mid;        // current max frq window
      r = mid - 1;
    } else { // shrink the window
      l = mid + 1;
    }
  }

  return (target_id - result + 1);
}

int maxFrequency(vector<int> &nums, int k) {
  int n = nums.size();

  sort(begin(nums), end(nums));

  // previous sum
  vector<long> preSum(n, 0);
  countPrefixSum(preSum, nums);

  int result = -1;

  for (int i = 0; i < n; ++i) // O(n)
  {
    int temp = binarySearch(i, k, preSum, nums); // O(log n)
    result = max(result, temp);
  }

  return result;
}

/*
    T.C = O(N log N)
    S.C = O(N)  <-- prefix sum vector
*/
