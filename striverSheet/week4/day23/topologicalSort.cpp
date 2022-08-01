#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> ans;
    if(e==0){
        for(int i=0; i<v; i++){
            ans.push_back(i);
        }
        return ans;
    }
    vector<int> indegre(v, 0);
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++){
        indegre[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegre[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int t= q.front();
        q.pop();
        ans.push_back(t);
        for(int i= 0; i<adj[t].size(); i++){
            indegre[adj[t][i]]--;
            if(indegre[adj[t][i]]==0){
                q.push(adj[t][i]);
            }
        }
    }
    return ans;
}