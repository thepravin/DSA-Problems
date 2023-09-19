// LeetCode : 539. Minimum Time Difference

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findMinDifference(vector<string> &timePoints)
{
    // step 1: convert time string to int
    vector<int> minites;

    for (int i = 0; i < timePoints.size(); i++)
    {
        string curr = timePoints[i];

        int hour = stoi(curr.substr(0, 2));
        int minite = stoi(curr.substr(3, 2)); // stoi = string to int
        int totalMinit = hour * 60 + minite;
        minites.push_back(totalMinit);
    }
    // step 2 :sort
    sort(minites.begin(), minites.end());

    // step 3 : difference and calculate min diff
    int n = minites.size();
    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = minites[i + 1] - minites[i];
        mini = min(min, diff);
    }

    // step 4: THIS IS THE GAME
    int lastDiff = (minites[0] + 1440) - minites[n - 1]; // 1440 => total minites in one day
    mini = min(min, lastDiff);

    return min;
}

int main()
{

    return 0;
}