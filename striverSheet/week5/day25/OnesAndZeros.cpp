#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101]= {0};
    int findMaxForm(vector<string>& strs, int m, int n) {
        for(int i=0; i<strs.size(); i++){
            vector<int> count= countZeroOne(strs[i]);
            for(int zero= m; zero>=count[0]; zero--){
                for(int one= n; one>=count[1]; one--){
                    dp[zero][one]= max(dp[zero-count[0]][one-count[1]]+1, dp[zero][one]);
                }
            }
        }
        return dp[m][n];
    }
    
    vector<int> countZeroOne(string s){
        vector<int> count(2, 0);
        for(int i=0; i<s.length(); i++){
            count[s[i]-'0']++;
        }
        return count;
    }
};