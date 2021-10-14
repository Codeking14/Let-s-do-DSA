#include<bits/stdc++.h>
using namespace std;

int knapsack(int i,int c,int* wt,int* price,int n)
{
   if(i==n || c==0)
   {
      return 0;
   }
   int profit1=0;
   if(wt[i]<=c)
   {
      profit1 = price[i] + knapsack(i+1,c-wt[i],wt,price,n);
   }
   int profit2 = knapsack(i+1,c,wt,price,n);
   return max(profit1,profit2);
}

int main()
{
   int n,c;
   cin>>n>>c;
   int wt[n];
   int price[n];
   for(int i=0;i<n;i++)
   {
      cin>>wt[i];
   }
   for(int i=0;i<n;i++)
   {
      cin>>price[i];
   }
   cout<<knapsack(0,c,wt,price,n);
}
