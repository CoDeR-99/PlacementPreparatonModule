#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans= INT_MIN;
        int count= 0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==1){
                count++;
            }
            else{
                ans= max(ans, count);
                count= 0;
            }
        }
        ans= max(ans, count);
        return ans;
    }
};

int main(){
    vector<int> vec= {1,1,0,1,1,1};
    Solution obj;
    int ans= obj.findMaxConsecutiveOnes(vec);
    cout<<"Maximum consecutive Ones: "<<ans;
    return 0;
}