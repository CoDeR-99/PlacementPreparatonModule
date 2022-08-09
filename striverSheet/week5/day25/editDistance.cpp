#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int r= word1.length();
        int c= word2.length();
        vector<vector<int>> dp(r+1, vector<int>(c+1));
        for(int i=0; i<=r; i++){
            for(int j=0; j<=c; j++){
                if(i==0){
                    dp[i][j]= j;
                }
                else if(j==0){
                    dp[i][j]= i;
                }
                else if(word1[i-1]==word2[j-1]){
                    dp[i][j]= dp[i-1][j-1];   //if character in the string is same we don't required to perform any opration and the previous will remian the answer
                }
                else{
                    dp[i][j]= min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[r][c];
    }
};

int main(){
    string s1= "horse";
    string s2= "ros";
    Solution obj;
    cout<<obj.minDistance(s1, s2);
    return 0;
}