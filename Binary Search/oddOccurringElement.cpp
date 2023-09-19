// Alaways two adjecent elements are same

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (s == e)
        {
            // only one element is present
            return s;
        }

        // If mid is Even or Odd
        if (mid % 2 == 0) // <--- Event
        {
            if (arr[mid] == arr[mid + 1])
            {
                // search in right side
                s = mid + 2;
            }
            else
            {
                // search in left side
                e = mid;
            }
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
            {
                // search in right
                s = mid + 1;
            }
            else
            {
                // search in left
                e = mid - 1;
            }
        }

        mid = s + (e - s) / 2;
    }
    return -1;
}

int main()
{
    vector<int> arr{-1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};

    int ans = search(arr);

    cout << "Index is : " << ans << endl;
    cout << "Element is : " << arr[ans] << endl;

    return 0;
}