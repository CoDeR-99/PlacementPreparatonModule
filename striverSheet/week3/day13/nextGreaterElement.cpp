#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2= nums2.size();
        vector<int> ans(n1);
        for(int i=0; i<n1; i++){
            ans[i]= -1;
        }
        map<int, int> mp;
        for(int i=0; i<n1; i++){
            mp[nums1[i]]= i;
        }
        stack<int> s;
        for(int i=0; i<n2; i++){
            if(s.empty()){
                if(mp.find(nums2[i]) != mp.end()){
                    s.push(nums2[i]);
                }
                else{
                    continue;
                }
            }
            else{
                if(s.top()>nums2[i]){
                    if(mp.find(nums2[i]) != mp.end()){
                        s.push(nums2[i]);
                    }
                }
                else{
                    while(!s.empty() && s.top()<nums2[i]){
                        ans[mp[s.top()]]= nums2[i];
                        s.pop();
                    }
                    if(mp.find(nums2[i]) != mp.end()){
                        s.push(nums2[i]);
                    }
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int> v1= {4, 1, 2};
    vector<int> v2= {1, 3, 4, 2};
    Solution obj;
    vector<int> vec= obj.nextGreaterElement(v1, v2);
    for(auto x: vec){
        cout<<x<<" ";
    }
    return 0;
}