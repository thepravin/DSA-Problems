// Leet Code - 658

#include<iostream>
#include<vector>
using namespace std;

vector<int>twoPointerApproach(vector<int>arr,int k,int x)
{
    int l=0;
    int h=arr.size()-1;

    while(h-l>=k)
    {
        if((x-arr[l])>(arr[h]-x))
        {
            l++;
        }else{
            h--;
        }
    }
    vector<int>ans;
    for (int i = l; i < h; i++)
    {
        arr.push_back(arr[i]);
    }
    return ans;
    
}

int main()
{
    vector<int>arr{1,2,3,4,5};
    int k=4;
    int x=3;

   cout<< twoPointerApproach(arr,k,x);

  

    return 0;
}