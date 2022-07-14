#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    void helper(int idx, string s, int n, vector<vector<string>> & vec, vector<string> &dp){
        if(idx==n){
            vec.push_back(dp);
            return;
        }
        for(int i=idx; i<n; i++){
            if(isPalindrome(s, idx, i)){
                dp.push_back(s.substr(idx, i-idx+1));
                helper(i+1, s, n, vec, dp);
                dp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string> dp;
        int n= s.length();
        helper(0, s, n, vec, dp);
        return vec;
    }
};

int main(){
    string s= "aabb";
    Solution obj;
    vector<vector<string>> vec= obj.partition(s);
    for(auto x: vec){
        cout<<"[";
        for(auto i:x){
            cout<<i<<" ";
        }
        cout<<"]\n";
    }
    return 0;
}