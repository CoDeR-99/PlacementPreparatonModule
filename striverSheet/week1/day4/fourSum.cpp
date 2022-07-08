#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vec;
        if(nums.size()==0){
            return vec;
        }
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                double tempt= (double)target-(double)nums[i]-(double)nums[j];
                int front= j+1;
                int back= n-1;
                while(front<back){
                    if(nums[front]+nums[back]==tempt){
                        vector<int> temp(4, 0);
                        temp[0]= (nums[i]);
                        temp[1]= (nums[j]);
                        temp[2]= (nums[front]);
                        temp[3]= (nums[back]);
                        vec.push_back(temp);
                        while(front<back && nums[front]==temp[2]){
                            front++;
                        }
                        while(front<back && nums[back]==temp[3]){
                            back--;
                        }
                    }
                    else if(nums[front]+nums[back]<tempt){
                        front++;
                    }
                    else{
                        back--;
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]){
                    j++;
                }
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return vec;
    }
};

int main(){
    vector<int> v= {1,0,-1,0,-2,2};
    int t= 0;
    Solution obj;
    vector<vector<int>> ans= obj.fourSum(v, t);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    return 0;
}