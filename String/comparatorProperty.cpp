// comparator is one of the arrgument in sort stl function
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool decendingOrder(int a,int b)
{
    return b<a;
}

int main()
{
    vector<int>arr{4,5,8,1,3,2};
    sort(arr.begin(),arr.end(),decendingOrder);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }

    return 0;
}