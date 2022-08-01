#include<bits/stdc++.h>
using namespace std;

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int x= edges[i][0];
        int y= edges[i][1];
        adj[x][y]= 1;
        adj[y][x]= 1;
    }
    vector<int> visited(n+1, 0);
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            stack<pair<int, int>> q; 
            q.push({i, -1});
            visited[i]= 1;
            while(!q.empty()){
            pair<int, int> t= q.top();
            q.pop();
            for(int j=1; j<=n; j++){
                if(adj[t.first][j]==1 && visited[j]==0){
                        q.push({j, t.first});
                        visited[j]= 1;
                }
                else if(adj[t.first][j]==1 && visited[j]==1 &&                   j!=t.second){
                    return "Yes";
                }
                }
            }
        }
        }
    return "No";
}