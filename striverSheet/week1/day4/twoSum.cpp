#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]= i;
        }
        return ans;
    }
};

int main(){
    vector<int> v= {2,7,11,15};
    int t= 9;
    Solution obj;
    vector<int> ans= obj.twoSum(v, t);
    for(auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}