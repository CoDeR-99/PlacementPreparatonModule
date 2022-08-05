#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res= *max_element(nums.begin(), nums.end());
        int currMin= 1, currMax= 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                currMin= currMax= 1;
                continue;
            }
            int temp1= currMin, temp2= currMax;
            currMin= min((min(temp1*nums[i], temp2*nums[i])), nums[i]);
            currMax= max((max(temp1*nums[i], temp2*nums[i])), nums[i]);
            res= max(res, currMax);
        }
        return res;
    }
};

int main(){
    vector<int> v= {2,3,-2,4};
    Solution obj;
    cout<<"Maximum Product Subarray: "<<obj.maxProduct(v);
    return 0;
}