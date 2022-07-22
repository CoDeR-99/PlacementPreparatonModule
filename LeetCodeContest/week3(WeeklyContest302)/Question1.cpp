#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int a= 0, b= 0;
        map<int, int> mp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto x: mp){
            a+= x.second/2;
            b+= x.second%2;
        }
        vector<int> vec(2);
        vec[0]= a;
        vec[1]= b;
        return vec;
    }
};