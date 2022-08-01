#include<bits/stdc++.h>
using namespace std;

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n= edges.size();
        if(n==0 || n==1 || n==2){
            return true;
        }
    vector<int> color(n, -1);
    queue<pair<int, int>> st;  //vertex, color
    for(int i=0; i<n; i++){
            if(color[i]== -1){
                st.push({i, 1});
                color[i]= 1;
                while(!st.empty()){
            pair<int, int> p= st.front();
            st.pop();
            for(int j=0; j<n; j++){
                if(edges[p.first][j]==1){
                    if(color[j]== -1){
                    if(p.second==1){
                        st.push({j, 0});
                        color[j]= 0;
                    }
                    else{
                        st.push({j, 1});
                        color[j]= 1;
                    }
                }
                else{
                    if(color[j]==p.second){
                        return false;
                    }
                }
                }
            }
        }
            }
        }
        return true;
}