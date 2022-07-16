#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size()+nums2.size();
        int mid= n/2;
        int count= 0;
        int temp1=0, temp2= 0;
        int i =0, j= 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                count++;
                if(count==mid){
                    temp1= nums1[i];
                }
                if(count==mid+1){
                    temp2= nums1[i];
                }
                i++;
            }
            else{
                count++;
                if(count==mid){
                    temp1= nums2[j];
                }
                if(count==mid+1){
                    temp2= nums2[j];
                }
                j++;
            } 
        }
        while(i<nums1.size()){
            count++;
                if(count==mid){
                    temp1= nums1[i];
                }
                if(count==mid+1){
                    temp2= nums1[i];
                }
                i++;
        }
        while(j<nums2.size()){
            count++;
                if(count==mid){
                    temp1= nums2[j];
                }
                if(count==mid+1){
                    temp2= nums2[j];
                }
                j++;
        }
        if(n%2==0){
            return ((double)(temp1+temp2))/((double)2);
        }
        else{
            return (double)temp2;
        }
    }
};

int main(){
    vector<int> nums1= {1, 3};
    vector<int> nums2= {2, 4};
    Solution obj;
    cout<<"Median: "<<obj.findMedianSortedArrays(nums1, nums2);
    return 0;
}