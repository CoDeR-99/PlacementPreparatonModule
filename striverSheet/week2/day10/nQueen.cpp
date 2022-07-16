#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row, int col, vector<string> vec, int n){
        int i= row;
        int j= col;
        while(i>=0 && j>=0){
            if(vec[i][j]=='Q') return false;
            i--;
            j--;
        }
        
        i= row; j= col;
        while(j>=0){
            if(vec[i][j]=='Q') return false;
            j--;
        }
        i= row; j= col;
        while(i<n && j>=0){
            if(vec[i][j]=='Q') return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(int idx, vector<string> &v, vector<vector<string>> &vec, int n){
        if(idx==n){
            vec.push_back(v);
            return;
        }
        for(int i=0; i<n; i++){
            if(isSafe(i, idx, v, n)){
                v[i][idx]= 'Q';
                helper(idx+1, v, vec, n);
                v[i][idx]= '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<string> v(n);
        string s(n, '.');
        for(int i=0; i<n; i++){
            v[i]= s;
        }
        helper(0, v, vec, n);
        return vec;
    }
};

int main(){
    int n=4;
    Solution obj;
    vector<vector<string>> vec= obj.solveNQueens(n);
    for(auto x: vec){
        for(auto i: x){
            cout<<i<<"\n";
        }
        cout<<"\n";
    }
    return 0;
}