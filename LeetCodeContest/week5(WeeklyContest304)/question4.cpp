#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> &dis, vector<bool> &vis, vector<int>& edges, int distance, int &ans, vector<bool> &extra){
        if(node != -1){
            if(!vis[node]){
                vis[node]= true;
                extra[node]= true;
                dis[node]= distance;
                dfs(edges[node], dis, vis,edges, distance+1, ans, extra);
            }
            else if(extra[node]){
                ans= max(ans, distance-dis[node]);
            }
            extra[node]= false;
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n= edges.size();
        vector<int> dis(n, -1);
        vector<bool> vis(n, false);
         vector<bool>extra(n, false);
        int ans= -1;  
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, dis, vis, edges, 0, ans, extra);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> edges= {3,3,4,2,3};
    Solution obj;
    cout<<obj.longestCycle(edges);
    return 0;
}