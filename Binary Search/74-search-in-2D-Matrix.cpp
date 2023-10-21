#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>> &matrix, int target, int start, int mid, int last)
{
    int row = matrix.size();
    int col = matrix[0].size();

    while (start <= last)
    {
        mid = (start + last) / 2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int midValue = matrix[rowIndex][colIndex];

        if (midValue == target)
        {
            return true;
        }
        else if (midValue < target)
        {
            start = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int last = matrix.size() * matrix[0].size() - 1;
    int start = 0;
    int mid;

    return binarySearch(matrix, target, start, mid, last);
}

int main()
{
    vector<vector<int>> matrix{{1, 3}};
    int target = 3;

    bool ans = searchMatrix(matrix, target);

    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}