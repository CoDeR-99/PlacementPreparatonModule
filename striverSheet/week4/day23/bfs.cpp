#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> adj(vertex, vector<int>(vertex, 0));
    for(auto x: edges){
        int i= x.first;
        int j= x.second;
        adj[i][j]=1;
        adj[j][i]=1;
    }
    vector<int> visited(vertex, 0);
    vector<int> ans;
    for(int i=0; i<vertex; i++){
        if(visited[i]==0){
            queue<int> q;
            q.push(i);
            visited[i]= 1;
            while(!q.empty()){
                int temp= q.front();
                ans.push_back(temp);
                q.pop();
                for(int j=0; j<vertex; j++){
                    if(adj[temp][j]==1 && visited[j]==0){
                        q.push(j);
                        visited[j]= 1;
                    }
                }
            }
        }
    }
    return ans;
}