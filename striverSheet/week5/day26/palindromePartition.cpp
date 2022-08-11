#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPalindrome(string s){
        if(s.length()==1){
            return true;
        }
        string temp= s;
        reverse(temp.begin(), temp.end());
        if(temp==s){
            return true;
        }
        return false;
    }
    
    int helper(string str, int i, int dp[]){
        if(i==str.length()){
            return 0;
        }
        if(dp[i] != -1)
        return dp[i];
        int ans= INT_MAX;
        string temp= "";
        for(int j=i; j<str.length(); j++){
            temp+= str[j];
            if(isPalindrome(temp)){
                int cost=(1+ helper(str, j+1, dp));
                ans= min(cost, ans);
            }
        }
        dp[i]= ans;
        return ans;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        int dp[str.length()];
        memset(dp, -1, sizeof(dp));
        return helper(str, 0, dp)-1;
    }
};

int main(){
    string str= "ababbbabbababa";
    Solution obj;
    cout<<obj.palindromicPartition(str);
    return 0;
}