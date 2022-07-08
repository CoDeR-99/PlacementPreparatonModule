#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int row= matrix.size();
        int col= matrix[0].size();
        int low= 0, high= (row*col-1);
        while(low<=high){
            int mid= (low+high)/2;
            if(matrix[mid/col][mid%col]<target){
                low= mid+1;
            }
            else if(matrix[mid/col][mid%col]>target){
                high= mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> v= {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    Solution obj;
    cout<<obj.searchMatrix(v, 2);
    return 0;
}