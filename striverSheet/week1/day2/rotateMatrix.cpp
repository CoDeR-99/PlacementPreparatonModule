#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r= matrix.size();
        int c= matrix[0].size();
        for(int i=0; i<r; i++){
            for(int j= i+1; j<c; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c/2; j++){
                swap(matrix[i][j], matrix[i][c-j-1]);
            }
        }
    }
};

int main(){
    Solution obj;
    vector<vector<int>> vec= {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    obj.rotate(vec);
    for(int i =0; i<vec.size(); i++){
        for(int j=0; j<vec[0].size(); j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}