#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool helper(string a, int idx, unordered_map<string, int> &mp, bool dp[]){
        if(idx==a.length()){
            return true;
        }
        for(int i= idx; i<a.length(); i++){
            if(dp[i]){
                return true;
            }
            if(mp.find(a.substr(idx, i-idx+1)) != mp.end() && helper(a, i+1, mp, dp)){
                dp[i]= true;
                return true;
            }
        }
        dp[idx]= false;
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_map<string, int> mp;
        int n= B.size();
        for(int i=0; i<n; i++){
            mp.insert({B[i], 1});
        }
        int m= A.length();
        bool dp[m];
        memset(dp, false, sizeof(dp));
        return helper(A, 0, mp, dp);
    }
};

int main(){
    string A= "ilike";
    vector<string> B= {"i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango""i", "like", "sam",
"sung", "samsung", "mobile",
"ice","cream", "icecream",
"man", "go", "mango"};
Solution obj;
cout<<obj.wordBreak(A, B);
    return 0;
}