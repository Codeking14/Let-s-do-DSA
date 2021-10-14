int sol[10001][13];


int dp(vector<int>&v,int x,int i){
    ///base case
    if(x<0){
        return -1;
    }
    if(x==0)
        return 0;
    if(i==-1)
        return -1;

    if(sol[x][i]!=-2)
        return sol[x][i];
    ///select this coin
    int ans1=dp(v,x-v[i],i);

    ///not select this coin
    int ans2= dp(v,x,i-1);

    if(ans1!=-1 && ans2!=-1){
        sol[x][i]= min(ans1+1,ans2);
        return sol[x][i];
    }

    if(ans1!=-1){
        sol[x][i]=ans1+1;
        return sol[x][i];
    }
    else{
        sol[x][i]=ans2;
        return sol[x][i];
    }






}


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        for(int i=0;i<=10000;i++){
            for(int j=0;j<=12;j++)
                sol[i][j]=-2;
        }
        return dp(coins,amount,n-1);
    }
};
