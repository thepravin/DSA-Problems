// Aggresive Cow

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int sol)
{ // can we place k cows at least mid distance between cow.

    int pos = arr[0];
    int cow = 1;

    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - pos) >= sol)
        {
            cow++;
            pos = arr[i]; // one more cow has been placed
        }

        if (cow == k)
        {
            return true;
        }
    }
    return false;
}

int findPosition(vector<int> arr, int n, int k)
{
    sort(arr.begin(), arr.end());

    if (k > n)
        return -1;

    int start = 0;
    int end = arr[arr.size()-1] - arr[0];
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, k, mid))
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
    vector<int> arr{10,1,2,7,5};
    int n = 5; // nu. of position
    int k = 3; // nu. of cows

    int ans = findPosition(arr, n, k);
    cout << ans << endl;

    return 0;
}