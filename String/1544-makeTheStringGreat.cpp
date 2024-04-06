#include <bits/stdc++.h>
using namespace std;


void merge(int arr[],int start,int mid,int end){
    int left[mid+1],right[end-mid+1];
    for(int i=start;i<mid;i++){
        left[i]=arr[i];
    }
    for(int i=mid;i<end;i++){
        right[i]=arr[i];
    }

    int leftIndex=0,rightIndex =0 , k=0;
    while(leftIndex <=mid+1 && rightIndex<=end-mid+1){
        if(left[leftIndex]<=right[rightIndex]){
            arr[k]=left[leftIndex];
            k++;
            leftIndex++;
        }else{
            arr[k]=right[rightIndex];
            k++;
            rightIndex++;
        }
    }

    while(leftIndex != mid+1){
         arr[k]=left[leftIndex];
            k++;
            leftIndex++;
    }
    while(rightIndex!= end-mid+1){
        arr[k]=right[rightIndex];
            k++;
            rightIndex++;
    }
}


void mergeSort(int arr[], int l, int r) {
   int start = I, end = r;
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,r);

    merge(arr,I,mid,r);    
}

int main()
{
  

    return 0;
}