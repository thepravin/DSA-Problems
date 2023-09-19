#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
void houseRobber(vector<int>&arr,int i,int sum,int& maxi)
{
    if(i>=arr.size())
    {
        maxi =max(sum,maxi);
        return;
    }

    // include
    houseRobber(arr,i+2,sum+arr[i],maxi);

    //exclude
    houseRobber(arr,i+1,sum,maxi);

}


int main()
{
 vector<int>arr{1,5,1,2,6};
 int sum=0;
 int maxi=0;
 int i=0;
 houseRobber(arr,i,sum,maxi);
 cout<<maxi;


    return 0;
}