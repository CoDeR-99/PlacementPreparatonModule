#include<bits/stdc++.h>

using namespace std;

int minKey(int dis[], bool mstSet[], int n) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 1; v <= n; v++) 
        if (mstSet[v] == false && dis[v] < min) 
            min = dis[v], min_index = v; 
  
    return min_index; 
} 

bool notReached(bool mstSet[], int n){
    for(int i=1; i<=n; i++){
        if(mstSet[i]==false){
            return true;
        }
    }
    return false;
}

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    int parent[n+1]; 
    int dis[n+1];
    bool mstSet[n+1]; 
    for(int i=0; i<=n; i++){
        dis[i]= INT_MAX;
        mstSet[i]= false;
    }
    dis[1] = 0; 
    parent[0]= -1;
    parent[1] = -1;
    //In minimum spanning we have v-1 edges
    int adj[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            adj[i][j]= -1;
        }
    }
    for(auto x: g){
        adj[x.first.first][x.first.second]= x.second;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int m= min(adj[i][j], adj[j][i]);
            if(m!= -1){
                adj[i][j] = m;
                adj[j][i] = m;
            }
        }
    }
    while(notReached(mstSet, n)){
        int u = minKey(dis, mstSet, n);
        mstSet[u] = true;
        for (int v = 1; v <= n; v++) 
            if (adj[u][v] != -1 && mstSet[v] == false && adj[u][v] < dis[v]) 
                parent[v] = u, dis[v] = adj[u][v]; 
    } 
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i], i}, dis[i]});
    }
    return ans;
}

int main()
{
    int n= 5; int m= 15;
    vector<pair<pair<int, int>, int>> g={ {{1, 2}, 21},
                                          {{1, 4}, 16},
                                          {{2, 1}, 12},
                                          {{2, 3}, 13},
                                          {{2, 4}, 18},
                                          {{2, 5}, 15},
                                          {{3, 2}, 13},
                                          {{3, 5}, 17},
                                          {{4, 1}, 16},
                                          {{4, 2}, 18},
                                          {{4, 5}, 19},
                                          {{5, 1}, 18},
                                          {{5, 2}, 15},
                                          {{5, 3}, 17},
                                          {{5, 4}, 19} };
    vector<pair<pair<int, int>, int>> ans= calculatePrimsMST(n, m, g);  
    cout<<"Answer: \n";
    for(auto x: ans){
        cout<<x.first.first<<" "<<x.first.second<<" "<<x.second<<"\n";
    }
    return 0;
}
