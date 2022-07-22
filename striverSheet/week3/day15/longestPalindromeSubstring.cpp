#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        if(n==1){
            return s;
        }
        if(n==2){
            if(s[0]==s[1]){
                return s;
            }
            else{
                string str= "";
                str+= s[0];
                return str;
            }
        }
        vector<vector<int>> vec(n, vector<int>(n));
        int ans= 1;
        string str= "";
        str+= s[0];
        int i=0, j=0;
        while(i<n && j<n){
            vec[i][j]= 1;
            i++; j++;
        }
        i=0;
        while(i<n-1){
            j= i+1;
            if(s[i]==s[j]){
                vec[i][j]=1;
                if(ans<(j-i+1)){
                    ans= j-i+1;
                    str= s.substr(i,ans);
                }
            }
            else{
                vec[i][j]=0;
            }
            i++;
        }
        for(int k= 2; k<=n-1; k++){
            i=0; j= k;
            while(i<n && j<n){
                if(s[i]==s[j] && vec[i+1][j-1]==1){
                    vec[i][j]=1;
                    if(ans<(j-i+1)){
                    ans= j-i+1;
                    str= s.substr(i,ans);
                }
                }
                else{
                    vec[i][j]= 0;
                }
                i++; j++;
            }
        }
        return str;
    }
};

int main(){
    string s= "babad";
    Solution obj;
    string ans= obj.longestPalindrome(s);
    cout<<"Longest Palindrome Substring: "<<ans;
    return 0;
}