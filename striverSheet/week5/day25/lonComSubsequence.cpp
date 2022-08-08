#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1= text1.length();
        int n2= text2.length();
        
        vector<vector<int>> vec(n1+1, vector<int>(n2+1, 0));
        
        for(int i= 1; i<=n1; i++){
            for(int j= 1; j<=n2; j++){
                if(text1[i-1]==text2[j-1]){
                    vec[i][j]= 1 + vec[i-1][j-1];
                }
                else{
                    vec[i][j]= max(vec[i][j-1], vec[i-1][j]);
                }
            }
        }
        return vec[n1][n2];
    }
};

int main(){
    string s1= "abcde";
    string s2= "ace";
    Solution obj;
    cout<<obj.longestCommonSubsequence(s1, s2);
    return 0;
}