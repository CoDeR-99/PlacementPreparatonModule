#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i= 0, j=0;
        int n= nums.size();
        while(j<n){
            if(nums[i] != nums[j]){
                nums[++i]= nums[j];
            }
            j++;
        }
        return i+1;
    }
};

int main(){
    vector<int> vec= {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution obj;
    int ans= obj.removeDuplicates(vec);
    for(int i=0; i<ans; i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}