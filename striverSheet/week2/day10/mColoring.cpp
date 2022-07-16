#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isColor(vector<vector<int>> graph, int edge,int i,int arr[], int n){
        for(int col=0; col<n; col++){
            if(graph[edge][col]==true && col!=edge){
                if(arr[col]==i){
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<int>> graph, int m, int n, int arr[], int edge){
        if(edge==n){
            return true;
        }
        for(int i=1; i<=m; i++){
            if(isColor(graph, edge, i, arr, n)){
                arr[edge]= i;
                if(helper(graph, m, n, arr, edge+1)){
                    return true;
                }
                else{
                    arr[edge]= 0;
                }
            }
        }
        return false;
    }
    bool graphColoring(vector<vector<int>> graph, int m, int n) {
        // your code here
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i]= 0;
        }
        return helper(graph, m, n, arr, 0);
    }
};

int main(){
    vector<vector<int>> vec={
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int n=4;
    int m= 3;
    Solution obj;
    bool ans= obj.graphColoring(vec, m, 4);
    if(ans){
        cout<<"Coloring Possible";
    }
    else{
        cout<<"Coloring not Possible";
    }
    return 0;
}