// Leet code 121

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

void profitRE(vector<int> &prices, int i, int &maxProfit, int &minPrice)
{
    // base case
    if (i == prices.size())
        return;

    // ek case
    if (minPrice > prices[i])
    {
        minPrice = prices[i];
    }
    int todayProfit = prices[i] - minPrice;
    if (todayProfit > maxProfit)
    {
        maxProfit = todayProfit;
    }

    // RE call
    profitRE(prices, i + 1, maxProfit, minPrice);
}

int maxProfit(vector<int> &prices)
{
    int maxProfit = INT_MIN;
    int minPrice = INT_MAX;

    profitRE(prices, 0, maxProfit, minPrice);

    return maxProfit;
}

int main()
{
    vector<int> arr{7, 1, 5, 3, 6, 4};

    int ans = maxProfit(arr);
    cout << ans << endl;

    return 0;
}