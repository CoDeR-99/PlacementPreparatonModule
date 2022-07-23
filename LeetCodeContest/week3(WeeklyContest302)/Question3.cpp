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

int main(){
    vector<string> num1= {"102","473","251","814"};
    vector<vector<int>> queries1= {{1,1},{2,3},{4,2},{1,2}};
    vector<string> num2= {"24","37","96","04"};
    vector<vector<int>> queries2= {{2,1},{2,2}};
    Solution obj;
    vector<int> ans1= obj.smallestTrimmedNumbers(num1, queries1);
    vector<int> ans2= obj.smallestTrimmedNumbers(num2, queries2);
    for(auto x: ans1){
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto x: ans2){
        cout<<x<<" ";
    }
    return 0;
}