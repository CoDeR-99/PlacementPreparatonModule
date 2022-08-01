#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> visited(V, 0);
    stack<int> st;
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        if(visited[i]==0){
            vector<int> traverse;
            st.push(i);
            visited[i]=1;
            while(!st.empty()){
            int temp= st.top();
            st.pop();
            traverse.push_back(temp);
            for(auto x: edges){
                if(x[0]==temp && visited[x[1]]==0){
                    st.push(x[1]);
                    visited[x[1]]= 1;
                }
                else if(x[1]==temp && visited[x[0]]==0){
                    st.push(x[0]);
                    visited[x[0]]= 1;
                }
            }
        }
            sort(traverse.begin(), traverse.end());
            ans.push_back(traverse);
        }
       
        
    }
     sort(ans.begin(), ans.end());
    return ans;
}