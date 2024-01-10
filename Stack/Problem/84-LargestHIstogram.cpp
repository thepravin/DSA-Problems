// LeetCode 84 : Largest Rectangular in Histogram

#include <iostream>
#include <stack>
#include <vector>
#include<limits.h>
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
        if (next[i]==-1)
        {
            n=size;
        }
        
        int width = n-p-1;
        int area = length*width;
        maxArea = max(area,maxArea);

    }
    
    return maxArea;

}

int main()
{
    vector<int> v = {2, 1, 5, 6, 2, 3};

    int ans = largestRectangleArea(v);

    cout << "Area is : " << ans << endl;

    return 0;
}