#include<bits/stdc++.h>
using namespace std;

void helper(int i, int j, vector<vector<int>> &maze, int n, vector<vector<int>> vis, vector<vector<int>> &ans){
    if(i==n-1 && j==n-1){
        vis[i][j]= 1;
        vector<int> temp;
        for(int I=0; I<n; I++){
            for(int J=0; J<n; J++){
                temp.push_back(vis[I][J]);
            }
        }
        ans.push_back(temp);
        return;
    }
    //downward
    if(i+1<n && maze[i+1][j]==1 && !vis[i+1][j]){
        vis[i][j]= 1;
        helper(i+1, j, maze, n, vis, ans);
        vis[i][j]= 0;
    }
    //left
    if(j-1>=0 && maze[i][j-1]==1 && !vis[i][j-1]){
        vis[i][j]= 1;
        helper(i, j-1, maze, n, vis, ans);
        vis[i][j]= 0;
    }
    //right
    if(j+1<n && maze[i][j+1]==1 && !vis[i][j+1]){
        vis[i][j]= 1;
        helper(i, j+1, maze, n, vis, ans);
        vis[i][j]= 0;
    }
    //upward
    if(i-1>=0 && maze[i-1][j]==1 && !vis[i-1][j]){
        vis[i][j]= 1;
        helper(i-1, j, maze, n, vis, ans);
        vis[i][j]= 0;
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> vis(n, vector<int>(n,0));
    if(maze[0][0]==1) helper(0, 0, maze, n, vis, ans);
    return ans;
}

int main(){
    vector<vector<int>> maze= {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    int n= maze.size();
    vector<vector<int>> ans= ratInAMaze(maze, n);
    for(auto x: ans){
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}