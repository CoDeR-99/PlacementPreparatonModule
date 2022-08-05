#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int> lis(n, 1);
        for(int i=n-1; i>=0; i--){
            for(int j= i+1; j<n; j++){
                if(nums[i]<nums[j]){
                    lis[i]= max(lis[i], 1+lis[j]);
                }
            }
        }
        return *max_element(lis.begin(), lis.end());
    }
};

int main(){
    vector<int> v= {10,9,2,5,3,7,101,18};
    Solution obj;
    cout<<"Length of longest increasing subsequence: "<<obj.lengthOfLIS(v);
    return 0;
}