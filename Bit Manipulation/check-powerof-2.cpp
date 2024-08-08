#include<iostream>
using namespace std;


int main(){
    int n = 16;

    if((n & (n-1)) == 0){
        cout<<n<<" is power of 2"<<endl;
    }else{
        cout<<"Not in power of 2 "<<endl;
    }
}