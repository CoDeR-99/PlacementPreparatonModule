#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max= 0;
        int ans= INT_MIN;
        for(int i=0; i<nums.size(); i++){
            max+= nums[i];
            if(ans<max){
                ans= max;
            }
            if(max<0){
                max= 0;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> vec= {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<obj.maxSubArray(vec);
    return 0;
}