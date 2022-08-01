#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& image, int sr, int sc, int color, int startColor){
        int row= image.size();
        int col= image[0].size();
        if(sr>=row || sc>=col || sr<0 || sc<0 || image[sr][sc]!=startColor || image[sr][sc]==color){
            return;
        }
        image[sr][sc]= color;
        helper(image, sr-1, sc, color, startColor);
        helper(image, sr+1, sc, color, startColor);
        helper(image, sr, sc+1, color, startColor);
        helper(image, sr, sc-1, color, startColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int row= image.size();
        int col= image[0].size();
        if(sr>=row || sc>=col || sr<0 || sc<0){
            return image;
        }
        int startColor= image[sr][sc];
        helper(image, sr, sc, color, startColor);
        return image;
    }
};