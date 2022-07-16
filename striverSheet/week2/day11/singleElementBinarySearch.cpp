#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i=0; int j= nums.size()-2;
        while(j>=i){
            int mid= (i+j)/2;
            if(nums[mid]==nums[mid^1]){
                i= mid+1;
            }
            else{
                j= mid-1;
            }
        }
        return nums[i];
    }
};

int main(){
    vector<int> nums={3,3,7,7,10,11,11};
    Solution obj;
    cout<<obj.singleNonDuplicate(nums);
    return 0;
}