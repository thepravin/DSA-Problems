// https://www.spoj.com/problems/PRATA/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int>cookRank,int np,int mid)
{
  int currP = 0; // initial cooked prata
  for(int i=0;i<cookRank.size();i++)
  {
    int R = cookRank[i];
    int j=1 , timeTaken = 0;

    while(true)
    {
      if(timeTaken + (R*j) <= mid)
      {
          ++currP;
          timeTaken +=(R*j);
          j++;
      }else{
        break;
      }
    }

    if(currP>=np){
      return true;
    }
  }
    return false;
}



int minTimeToCompleteOrder(vector<int>cookRank,int nP,int nC)
{
  int start=0;
  int hightRank = *max_element(cookRank.begin(),cookRank.end());
  int end=hightRank*(nP*(nP+1))/2;
  int ans = -1;
  while(start<=end)
  { 
    int mid = start+(end-start)/2;
    if(isPossible(cookRank,nP,mid))
    {
      ans = mid;
      end= mid-1;  // find minimum time
    }else
    {
      start= mid +1;
    }

  }
  return ans;
}

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    int nP,nC;
    cin>>nP>>nC;
    vector<int>cookRank;

    while(nC--)
    {
      int R; cin>>R;
      cookRank.push_back(R);
    }

    cout<<minTimeToCompleteOrder(cookRank,nP,nC)<<endl;
   }


    return 0;
}