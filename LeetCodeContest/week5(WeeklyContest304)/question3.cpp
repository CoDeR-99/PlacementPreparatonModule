#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> &dis, vector<bool> &vis, vector<int>& edges, int distance){
        if(node != -1 && !vis[node]){
            vis[node]= true;
            dis[node]= distance;
            dfs(edges[node], dis, vis,edges, distance+1);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n= edges.size();
        vector<int> dis1(n, -1);
        vector<int> dis2(n, -1);
        vector<bool> vis(n, false);
        
        dfs(node1, dis1, vis,edges, 0);
        vis.assign(n, false);
        dfs(node2, dis2, vis, edges, 0);
        
        int ans= n;  //max distance will be no of edges and we have to find mini so initialise with maxi
        int result= -1;
        for(int i=0; i<n; i++){
            if(dis1[i] != -1 && dis2[i] != -1){
                if(max(dis1[i], dis2[i]) < ans){
                    ans= max(dis1[i], dis2[i]);
                    result= i;
                }
            }
        }
        return result;
    }
};

int main(){
    vector<int> edges= {2,2,3,-1};
    int node1= 0, node2= 1;
    Solution obj;
    cout<<obj.closestMeetingNode(edges, node1, node2);
    return 0;
}