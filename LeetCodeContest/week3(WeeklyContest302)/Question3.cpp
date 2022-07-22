#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n= queries.size();
        int m= nums.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            vector<pair<string, int>> v(m);  //string, index original
            for(int j=0; j<m; j++){
                string tnum;
                if(nums[j].length()<queries[i][1]){
                    tnum= nums[j];
                }
                else{
                    tnum= nums[j].substr((nums[j].length()-queries[i][1]));
                }
                
                v[j]= {tnum, j};
            }
            sort(v.begin(), v.end());
            int idx= queries[i][0]-1;
            ans[i]= v[idx].second;
        }
        return ans;
    }
};