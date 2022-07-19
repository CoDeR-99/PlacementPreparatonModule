#include<bits/stdc++.h>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> idx(k, 0); //index at each array
    for(int i=0; i<k; i++){
        pq.push({kArrays[i][0], i}); //i tells about the array
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int, int> p= pq.top();
        pq.pop();
        ans.push_back(p.first);
        if(idx[p.second]+1 < kArrays[p.second].size()){
            pq.push({kArrays[p.second][idx[p.second]+1], p.second});
        }
        idx[p.second]++;
    }
    return ans;
}

int main(){
    vector<vector<int>> vec= {
        {24, 35, 43, 57, 66},
        {11, 60, 90, 99},
        {30, 55,66,  78}
    };
    vector<int> ans= mergeKSortedArrays(vec, 3);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}