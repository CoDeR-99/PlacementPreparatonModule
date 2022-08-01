#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCycle(vector<vector<int>> adj, vector<int> &vis, int curr){
        if(vis[curr]==2){
            return true;
        }
        vis[curr]= 2;
        for(int i=0; i<adj[curr].size(); i++){
            if(vis[adj[curr][i]] != 1){
                if(isCycle(adj, vis, adj[curr][i]))
                    return true;
            }
        }
        vis[curr]= 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(vis[i]==0){
                if(isCycle(adj, vis, i)){
                    return false;
                }
            }
        }
        return true;
    }
};