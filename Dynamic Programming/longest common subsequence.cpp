#include<bits/stdc++.h>
using namespace std;

int LCS(string s1,string s2,unordered_map<string,int> dp)
{
   if(s1.empty() || s2.empty())
      return 0;

   string s = s1 + "|" +s2;

   if(dp.find(s) == dp.end())
   {
      if(s1[0] == s2[0])
         dp[s] = 1 + LCS(s1.substr(1),s2.substr(1),dp);
      else
      {
         dp[s] = max( LCS( s1.substr(1) , s2 , dp) , LCS(s1 , s2.substr(1), dp));
      }
   }
   return dp[s];
}

int main()
{
   string s1,s2;
   cin>>s1>>s2;

   unordered_map<string,int> m;

   cout<<LCS(s1,s2,m);
}
