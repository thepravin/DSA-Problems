// Replaces Spaces
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

void replaceSpace(char name[])
{
    for (int i = 0; i < strlen(name); i++)
    {
        if (name[i]==' ')
        {
            name[i]='@';
        }
        
    }
    
}

int main()
{
   char name[100]="Pravin Nalawade";
   replaceSpace(name);
   cout<<"New : "<<name<<endl;


    return 0;
}