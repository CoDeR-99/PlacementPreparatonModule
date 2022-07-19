#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto x: mp){
            if(pq.size()+1<=k){
                pq.push({x.second, x.first});
            }
            else{
                if(x.second<=pq.top().first){
                    continue;
                }
                else{
                    pq.pop();
                    pq.push({x.second, x.first});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main(){
    vector<int> vec= {1, 1, 1, 2, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 5};
    int k= 2;
    Solution obj;
    vector<int> ans= obj.topKFrequent(vec, k);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}