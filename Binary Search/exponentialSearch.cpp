
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

int binarySearch(int arr[], int start,int end,int x)
{
    int mid=start+(end-start)/2;
    
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==x) return mid;

        else if (x>arr[mid])
        {
            start=mid+1;
        }else{
            end=mid-1;
        }
        
    }
    return -1;
}

int expSearch(int arr[],int size,int x)
{
    if(arr[0]==x) return 0;

    int i=1;
    while(i<size && arr[i]<=x)
    {
        i= i*2; // i*=2//i=i<<1;
    }

    return binarySearch(arr,i/2,min(i,size-1),x);
}

int main()
{
    int arr[] = {3,4,5,6,11,12,13,14,15,56,70};
    int size = sizeof(arr)/sizeof(int);
    int x = 13;
    int ans = expSearch(arr,size,x);
    cout<<ans<<endl;

    return 0;
}