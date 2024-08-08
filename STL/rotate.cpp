#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> arr ={1,2,3,4,5,6};

    rotate(arr.begin(),arr.begin()+3,arr.end());

    for(auto& i : arr){
        cout<<i<<" ";
    }

}