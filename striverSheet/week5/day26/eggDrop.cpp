#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int dp[205][205];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    
    int eggDrop(int n, int k) 
    {
        // your code here
        if(n==1 || k==0 || k==1){
            return k;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int ans= INT_MAX;
        for(int i=1; i<=k; i++){
            int c1= eggDrop(n-1, i-1);  //egg break;
            int c2= eggDrop(n, k-i);    //egg not break;
            int worst= 1+max(c1, c2);
            ans= min(ans, worst);
        }
        return dp[n][k]= ans;
    }
};

int main(){
    int n= 2; int k= 10;
    Solution obj;
    cout<<obj.eggDrop(n, k);
    return 0;
}