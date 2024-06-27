#include <iostream>
using namespace std;
#include <map>
#include <unordered_map>


int main()
{

    // creation
    unordered_map<string, int> m;

//----------------->>>> insertion <<<---------------
    // 1
    pair<string, int> p = make_pair("pravin", 3);
    m.insert(p);

    // 2
    pair<string, int> q("home", 2);
    m.insert(q);

    // 3
    m["city"] = 2;
    // cout<<m["city"]<<endl;

    // what will happen ???
    m["city"] = 5; // if key is present then update value
    // cout<<m["city"]<<endl;


//----------------->>>> Search <<<---------------
    // cout<<m["pravin"]<<endl;
    // cout<<m.at("pravin")<<endl;

    // Important for MCQ
    // Type 1 
        //cout<<m.at("unknownKey")<<endl; // o/p => give out of range error
    // Type 2
        // cout<<m["unknownKey"]<<endl;  // first find if not present then make new entry with 0 , o/t=> 0
        // cout<<m.at("unknownKey")<<endl; // o/t => 0


//----------------->>>> Size <<<---------------
// cout<<"Size : "<<m.size()<<endl;


//----------------->>>> check present of not <<<---------------
    // if present then 1 , if not then 0
    // cout<<m.count("pravin")<<endl; // o/p=> 1
    // cout<<m.count("present")<<endl; // o/p => 0

//----------------->>>> Erase <<<---------------
// cout<<"Size : "<<m.size()<<endl;
// m.erase("pravin");
// cout<<"Size : "<<m.size()<<endl;


//----------------->>>> print <<<---------------
// Type 1 ==> using for loop
/*
for(auto i:m){
    cout<<i.first<<":"<<i.second<<endl;
}
*/

// Type 2 ==> using iterator
/*
unordered_map<string,int>:: iterator it = m.begin();

while (it != m.end())
{
    cout<<it->first<<":"<<it->second<<endl;
    it++;
}
*/






    return 0;
}