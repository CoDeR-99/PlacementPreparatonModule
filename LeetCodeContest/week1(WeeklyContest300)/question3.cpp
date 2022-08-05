#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define M 1000000007

class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
         vector<ll> dp(n+1 , 0);
        dp[1] = 1;
        ll num = 0;
        for(ll i=2 ; i<=n ; i++) {
            ll num1 = dp[max(i - d , 0LL)] , num2 = dp[max(i - f , 0LL)];
            dp[i] = (num%M + num1%M - num2%M + M)%M;
            num = dp[i]; 
        }
        ll ans = 0;
        for(ll i=n-f+1 ; i<=n ; i++) {
            ans = (ans%M + dp[i]%M)%M;
        }
        return ans;
    }
};

int main(){
    int n = 6, delay = 2, forget = 4;
    Solution obj;
    cout<<obj.peopleAwareOfSecret(n, delay, forget);
    return 0;
}