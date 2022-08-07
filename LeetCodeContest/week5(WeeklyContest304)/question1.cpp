#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=0){
                mp[nums[i]]++;
            }
        }
        return mp.size();
    }
};

int main(){
    vector<int> nums= {1,5,0,3,5};
    Solution obj;
    cout<<obj.minimumOperations(nums);
    return 0;
}