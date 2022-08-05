#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dis(V, 100000000);
        dis[S]= 0;
        for(int i=1; i<=V-1; i++){
            for(auto x: adj){
                int u= x[0];
                int v= x[1];
                int w= x[2];
                if(dis[u]==100000000){
                    continue;
                }
                if(dis[u]+w<dis[v]){
                    dis[v]= dis[u]+w;
                }
            }
        }
        return dis;
    }
};