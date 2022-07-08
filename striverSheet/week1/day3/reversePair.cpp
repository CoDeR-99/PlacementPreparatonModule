#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void mergeSort(vector<int> &nums, int start, int mid, int end, int &ans){
        int n1= mid-start+1;
        int n2= end-mid;
        int arr1[n1], arr2[n2];
        for(int i=0; i<n1; i++){
            arr1[i]= nums[start+i];
        }
        for(int i=0; i<n2; i++){
            arr2[i]= nums[mid+i+1];
        }
        int j= 0;
        for(int i=0; i<n1; i++){
            while(j<n2 && arr1[i]> 2LL*arr2[j]){
                j++;
                
            }
            ans+= j;
        }
        int i=0, k= start;
        j= 0;
        while(i<n1 && j<n2){
            if(arr1[i] <= arr2[j]){
                nums[k++]= arr1[i++];
            }
            else{
                nums[k++]= arr2[j++];
            }
        }
        while(i<n1){
            nums[k++]= arr1[i++];
        }
        while(j<n2){
            nums[k++]= arr2[j++];
        }
    }
    
    void merge(vector<int> &nums,int i, int j, int &ans){
        if(i<j){
            int mid= (i+j)/2;
            merge(nums, i, mid, ans);
            merge(nums, mid+1, j, ans);
            mergeSort(nums, i, mid, j, ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans= 0;
        int n= nums.size();
        merge(nums,0, n-1, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v = {2,4,3,5,1};
    cout<<obj.reversePairs(v);
    return 0;
}