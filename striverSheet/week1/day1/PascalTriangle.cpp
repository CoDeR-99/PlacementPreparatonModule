#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec(numRows);
        for(int i=0; i<numRows; i++){
            vec[i].resize(i+1);
            for(int j=0; j<i+1; j++){
                if(j==0 || j==i){
                    vec[i][j]= 1;
                }
                else{
                    vec[i][j]= vec[i-1][j-1]+vec[i-1][j];
                }
            }
        }
        return vec;
    }
};

int main(){
    Solution obj;
    int n= 5;
    vector<vector<int>> ans= obj.generate(n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}