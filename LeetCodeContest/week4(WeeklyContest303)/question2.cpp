#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        for(int i=0; i<r; i++){
            string temp= "";
            for(int j=0; j<c; j++){
                temp+= to_string(grid[i][j]);
                temp+= to_string(0);
            }
            mp1[temp]++;
        }
        for(int i=0; i<c; i++){
            string temp= "";
            for(int j=0; j<r; j++){
                temp+= to_string(grid[j][i]);
                temp+= to_string(0);
            }
            mp2[temp]++;
        }
        int ans= 0;
        for(auto x: mp1){
            if(mp2.find(x.first) != mp2.end()){
                ans+=( x.second * mp2[x.first] );
            }
        }
        return ans;
    }
};

int main(){
    vector<vector<int>> grid= {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
    Solution obj;
    cout<<obj.equalPairs(grid);
    return 0;
}