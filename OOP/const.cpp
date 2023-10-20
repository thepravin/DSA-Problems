#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
   // ============> const with pointers <===============
   
/*    //const int*a = new int(2); // const data , non const pointer
    int const *a = new int(2); // same as line 10
    cout<<*a<<endl;
    // *a=20 ; // cant change the content of pointer

    int b = 20;
    a = &b; // pointer can be reassigned
    cout<<*a<<endl;


 */

/* 
    // CONST Pointer , NON-CONST data.
    int *const a=new int(2);
    cout<<*a<<endl;
    *a=20; 
    cout<<*a<<endl;

    int b=50;
    //a= &b; // nahi chalega, CONST pointer
 
 */

    // CONST pointer , CONST data
    const int*const a= new int(10);
    cout<<*a<<endl;
    // *a=50; // nahi chalega
    int b=24;
  //  a=&b; // nahi chalega


    return 0;
}