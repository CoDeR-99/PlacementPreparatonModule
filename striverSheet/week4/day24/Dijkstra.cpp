#include<bits/stdc++.h>
using namespace std;

bool notVisited(vector<int> &vis){
    for(int i=0; i<vis.size(); i++){
        if(vis[i]==0){
            return true;
        }
    }
    return false;
}
int mini(vector<int> &dis, vector<int> &vis){
    int midx= -1;
    int mval= INT_MAX;
    for(int i=0; i<dis.size(); i++){
        if(mval>dis[i] && vis[i]==0){
            mval= dis[i];
            midx= i;
        }
    }
    return midx;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<vector<pair<int, int>>> adj(vertices);
    for(int i=0; i<edges; i++){
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    // for(int i=0; i<edges; i++){
    //     for(auto x: adj[i]){
    //         cout<<i<<" "<<x.first<<" "<<x.second<<"\n";
    //     }
    // }
    vector<int> vis(vertices, 0);
    vector<int> dis(vertices, INT_MAX);
    dis[source]= 0;
    while(notVisited(vis)){
        int u= mini(dis, vis);
        // cout<<u<<"\n";
        vis[u]= 1;
        for(auto x: adj[u]){
            if(dis[u]+x.second<dis[x.first] && vis[x.first]==0){
                dis[x.first]= dis[u]+x.second;
            }
        }
    }
    return dis;
}

int main()
{
    int v= 5, e= 7, s= 0;
    vector<vector<int>> vec= {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, 
    {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};
    vector<int> ans= dijkstra(vec, v, e, s);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}