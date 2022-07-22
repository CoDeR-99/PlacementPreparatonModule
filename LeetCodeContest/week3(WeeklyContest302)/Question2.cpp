#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfDigit(int n){
        int sum=0;
        for(int i=n; i>0; i= i/10){
            sum+= i%10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans= -1;
        map<int, int> mp; //<sum, number>
        int n= nums.size();
        for(int i=0; i<n; i++){
            int temp= sumOfDigit(nums[i]);
            if(mp.find(temp) != mp.end()){
                ans= max(ans, mp[temp]+nums[i]);
                if(mp[temp]<nums[i]){
                    mp[temp]= nums[i];
                }
            }
            else{
                mp[temp]= nums[i];
            }
        }
        return ans;
    }
};