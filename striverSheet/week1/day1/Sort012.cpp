#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n= nums.size();
        int low= 0, mid= 0;
        int high= n-1;
        while(mid<=high){
            if(nums[mid]==2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else if(nums[mid]==0){
                swap(nums[low], nums[mid]);
                low++; mid++;
            }
        }
    }
};

int main(){
    Solution obj;
    vector<int> vec= {2, 0, 2, 1, 1, 0};
    obj.sortColors(vec);
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    return 0;
}