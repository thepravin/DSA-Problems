// GFG = Allocate minimum number of pages

#include <iostream>
#include <numeric>
using namespace std;

bool isPossibleSol(int A[], int N, int M, int sol)
{
    int pageSum = 0;
    int student = 1;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol) // number of pages greater than solution
        {
            return false;
        }

        if (pageSum + A[i] > sol)
        {
            student++;
            pageSum = A[i];
            if (student > M) // nu of student is greater than given student
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{

    if (M > N)
    {
        return -1;
    }

    int start = 0;
    int end = accumulate(A, A + N, 0); // total pages alloceted for one student it is all pages so it find sum of all pages
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (isPossibleSol(A, N, M, mid))
        {
            // store the ans
            ans = mid;

            // find the minimiz sol.
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
    int A[] = {12, 34, 67, 90};
    int N = 4; // number of books
    int M = 2; // number of students

    int ans = findPages(A, N, M);
    cout << ans << endl;

    return 0;
}