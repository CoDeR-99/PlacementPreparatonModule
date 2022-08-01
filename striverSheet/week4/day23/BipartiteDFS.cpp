#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        if(n==0 || n==1 || n==2){
            return true;
        }
        vector<int> color(n, -1);
        stack<pair<int, int>> st;  //vertex, color
        for(int i=0; i<n; i++){
            if(color[i]== -1){
                st.push({i, 1});
                color[i]= 1;
                while(!st.empty()){
            pair<int, int> p= st.top();
            st.pop();
            for(auto x: graph[p.first]){
                if(color[x]== -1){
                    if(p.second==1){
                        st.push({x, 0});
                        color[x]= 0;
                    }
                    else{
                        st.push({x, 1});
                        color[x]= 1;
                    }
                }
                else{
                    if(color[x]==p.second){
                        return false;
                    }
                }
            }
        }
            }
        }
        return true;
    }
};