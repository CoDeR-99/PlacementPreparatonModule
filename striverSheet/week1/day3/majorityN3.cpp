#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1= 0, candidate2= 0;
        int count1= 0, count2= 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==candidate1){
                count1++;
            }
            else if(nums[i]==candidate2){
                count2++;
            }
            else if(count1==0){
                candidate1= nums[i];
                count1++;
            }
            else if(count2==0){
                candidate2= nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int> vec;
        count1= 0; count2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==candidate1){
                count1++;
            }
            else if(nums[i]==candidate2){
                count2++;
            }
        }
        if(count1>(nums.size()/3)){
            vec.push_back(candidate1);
        }
        if(count2>(nums.size()/3)){
            vec.push_back(candidate2);
        }
        return vec;
    }
};

int main(){
    Solution obj;
    vector<int> v= {2, 2, 1, 1, 1, 2, 2};
    vector<int> vec= obj.majorityElement(v);
    sort(vec.begin(), vec.end());
    for(auto i:vec){
        cout<<i<<" ";
    }
    return 0;
}