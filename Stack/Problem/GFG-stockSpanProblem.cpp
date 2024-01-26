
// GFG - Stock Span Problem

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate the span of stockâ€™s price for all n days.
vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    vector<int> ans;
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        int span = 1;
        while (!st.empty() && st.top().first <= price[i])
        {
            span += st.top().second;
            st.pop();
        }
        st.push({price[i], span});
        ans.push_back(span);
    }

    return ans;
}

int main()
{
    int n = 7;
    int v[n] = {100, 80, 60, 70, 60, 75, 85};

    vector<int> ans = calculateSpan(v, n);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}