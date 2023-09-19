#include <iostream>
using namespace std;

bool isPossibleSolution(int A[], int n, int k, long long mid)
{
    int timeSum = 0;
    int c = 1; // painter
    for (int i = 0; i < n; i++)
    {
        if (A[i] > mid) // current bord length is greate than mid or solution
        {
            return false;
        }

        if (timeSum + A[i] > mid)
        {
            c++;
            timeSum = A[i];
            if (c > k)
            {
                return false;
            }
        }
        else
        {
            timeSum = timeSum + A[i];
        }
    }
    return true;
}

long long minTime(int A[], int n, int k)
{
    long long int start = 0;
    long long int end = 0; // user give all bords to one painter so end is sum of all
    for (int i = 0; i < n; i++)
    {
        end = end + A[i];
    }
    long long ans = -1;

    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (isPossibleSolution(A, n, k, mid))
        {
            // Store
            ans = mid;
            // find another minimum time
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int A[] = {2,9,2,4,5,10,3,3,4,1};
    int n = 10; // number of bords
    int k = 2; // number of painters

    long long ans = minTime(A, n, k);
    cout << ans << endl;

    return 0;
}