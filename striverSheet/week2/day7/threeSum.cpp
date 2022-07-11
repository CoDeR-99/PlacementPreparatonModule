#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        if(nums.empty()){
            return vec;
        }
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i= 0; i<n; i++){
            int front= i+1;
            int back= n-1;
            while(front<back){
                int k= nums[i]+nums[front]+nums[back];
                if(k>0){
                    back--;
                }
                else if(k<0){
                    front++;
                }
                else{
                    vector<int> v(3, 0);
                    v[0]= nums[i];
                    v[1]= nums[front];
                    v[2]= nums[back];
                    vec.push_back(v);
                    while (front < back && nums[front] == v[1]) ++front;
                    while (front < back && nums[back] == v[2]) --back;
                }
                
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return vec;
    }
};

int main(){
    vector<int> vec= {-1, 0, 1, 2, -1, 4};
    Solution obj;
    vector<vector<int>> ans= obj.threeSum(vec);
    for(auto x: ans){
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}