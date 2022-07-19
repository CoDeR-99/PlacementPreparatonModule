#include<bits/stdc++.h>
using namespace std;

int smallerThanMid(int mid, vector<int> vec){
    int l=0; int h= vec.size()-1;
    while(l<=h){
        int m= (l+h)/2;
        if(vec[m]<=mid){
            l= m+1;
        }
        else{
            h= m-1;
        }
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low= 1;
    int high= 1e9;
    int row= matrix.size();
    int col= matrix[0].size();
    while(low<=high){
        int mid= low + (high-low)/2;
        int count= 0;
        for(int i=0; i<row; i++){
            count+= smallerThanMid(mid, matrix[i]);
        }
        if(count<=(row*col)/2){
            low= mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return low;
}

int main(){
    vector<vector<int>> vec= {
        {2, 6, 9},
        {1, 5, 11},
        {3, 7, 8}
    };
    cout<<"Median of given Matrix: "<<getMedian(vec);
    return 0;
}