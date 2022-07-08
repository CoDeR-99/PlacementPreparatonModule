#include<bits/stdc++.h>
using namespace std;

    void setZeroes(vector<vector<int>>& matrix) {
        int r= matrix.size();
        int c= matrix[0].size();
        vector<int> row(r, 0);
        vector<int> col(c, 0);
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]==0){
                    row[i]= -1;
                    col[j]= -1;
                }
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(row[i]== -1 || col[j]== -1){
                    matrix[i][j]= 0;               
                }
            }
        }
    }

    int main() {
        vector < vector < int >> arr;
        arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
        setZeroes(arr);
        cout << "The Final Matrix is " << endl;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                cout << arr[i][j] << " ";
        }
        cout << "\n";
        }
    }
