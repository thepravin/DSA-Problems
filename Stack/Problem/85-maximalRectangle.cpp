// LeetCode 85 - Maxiaml Rectangle.cpp

#include <iostream>
#include <stack>
#include <vector>
#include <limits.h>
using namespace std;

// Next Smaller Elements
vector<int> nextSmallerElements(vector<int> v)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(v.size());

    for (int i = v.size() - 1; i >= 0; i--) // right to left
    {
        int curr = v[i];

        // check curr element with stack top
        while (st.top() != -1 && v[st.top()] >= curr)
        {
            st.pop();
        }
        // chota element mil gaya
        ans[i] = st.top();

        // push curr index in stack at any condition
        st.push(i);
    }
    return ans;
}

// Previous smaller
vector<int> previousSmaller(vector<int> input)
{
    vector<int> ans(input.size());
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < input.size(); i++) // left to right
    {
        int curr = input[i];

        while (st.top() != -1 && input[st.top()] >= curr)
        {
            st.pop();
        }

        ans[i] = st.top();

        st.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    // Step 1 : find prvious smaller index
    vector<int> prev = previousSmaller(heights);

    // step 2 : find next smaller index
    vector<int> next = nextSmallerElements(heights);

    // step 3: find width and area
    int maxArea = INT_MIN;
    int size = heights.size();

    for (int i = 0; i < heights.size(); i++)
    {
        int length = heights[i];
        int p = prev[i];
        int n = next[i];
        if (next[i] == -1)
        {
            n = size;
        }

        int width = n - p - 1;
        int area = length * width;
        maxArea = max(area, maxArea);
    }

    return maxArea;
}

// ************* Coding Ninjas *************

int maxArea(vector<vector<int>> &v, int n, int m)
{
    // step 1 : largest area of first row
    int area = largestRectangleArea(v[0]);

    // adding next row's
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j])
            {
                // add curr element with same column previous row
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }

    return area;
}
// ********************* LeetCode*******************
/* int maximalRectangle(vector<vector<char>> &matrix)
{
    // convert char to int
    vector<vector<int>> v;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        vector<int> t; // one row
        for (int j = 0; j < m; j++)
        {
            t.push_back(matrix[i][j] - '0');
        }
        v.push_back(t);
    }

    // step 1 : largest area of first row
    int area = largestRectangleArea(v[0]);

    // adding next row's
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j])
            {
                // add curr element with same column previous row
                v[i][j] += v[i - 1][j];
            }
            else
            {
                v[i][j] = 0;
            }
        }
        area = max(area, largestRectangleArea(v[i]));
    }

    return area;
} */

int main()
{

    vector<vector<int>> v = {{0, 1, 1, 0},
                              {1, 1, 1, 1},
                              {1, 1, 1, 1},
                              {1, 1, 0, 0}};
    /*
        vector<vector<char>> v = {{0, 1, 1, 0},
                                 {1, 1, 1, 1},
                                 {1, 1, 1, 1},
                                 {1, 1, 0, 0}};
     */
    cout << maxArea(v, 4, 4) << endl;

    return 0;
}