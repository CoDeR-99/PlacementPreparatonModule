#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =m-1, j= 0;
        while(i>=0 && j<n){
            if(nums1[i]<=nums2[j]){
                j++;
            }
            else{
                swap(nums1[i], nums2[j]);
                i--;
            }
        }
        for(int i=0; i<n; i++){
            nums1[m+i]= nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};

int main(){
    vector<int> nums1= {4, 0, 0, 0, 0, 0};
    vector<int> nums2= {1, 2, 3, 5, 6};
    int m= 1;
    int n= 5;
    Solution obj;
    obj.merge(nums1, m, nums2, n);
    for(int i=0; i<n+m; i++){
        cout<<nums1[i]<<" ";
    }
    return 0;
}