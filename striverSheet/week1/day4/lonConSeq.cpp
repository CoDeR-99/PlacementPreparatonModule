#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int n= nums.size();
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp.insert({nums[i], 1});
        }
        int ans= 1, curr=1, count=0;
        int prev;
        for(auto x: mp){
            if(count==0){
                prev= x.first;
                count++;
            }
            else{
                if(prev+1==x.first){
                    curr++;
                    prev= x.first; 
                }
                else{
                    ans= max(ans, curr);
                    curr= 1;
                    prev= x.first;
                }
            }
        }
        ans= max(ans, curr);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> nums= {0,3,7,2,5,8,4,6,0,1};
    cout<<obj.longestConsecutive(nums);
    return 0;
}
