#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n= nums.size();
        for(int i=0; i<n; i++){
            if(pq.size()+1 <= k){
                pq.push(nums[i]);
            }
            else{
                if(nums[i]<=pq.top()){
                    continue;
                }
                else{
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
        return pq.top();
    }
};

int main(){
    vector<int> vec= {3,2,3,1,2,4,5,5,6};
    int k=4;
    Solution obj;
    cout<<k<<"th largest element: "<<obj.findKthLargest(vec, k);
    return 0;
}