// EKO -SPOJ PROBLE : https://www.spoj.com/problems/EKO/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findHeight(vector<int> arr, int n, int m)
{
    sort(arr.begin(), arr.end());

    int start = 0;
    int end = arr[n - 1]; // max element in array
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
            {
                sum = sum + (arr[i] - mid);
            }
        }

        if (sum >= m)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5;  // number of trees
    int m = 20; // at least how much wood is required
    vector<int> arr{4, 42, 40, 26, 46};
    int ans = findHeight(arr, n, m);
    cout << ans << endl;

    return 0;
}