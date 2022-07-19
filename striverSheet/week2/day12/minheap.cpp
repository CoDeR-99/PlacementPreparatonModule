#include<bits/stdc++.h>
using namespace std;

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> vec;
    for(int i=0; i<n; i++){
        if(q[i][0]==0){
            pq.push(q[i][1]);
        }
        else{
            vec.push_back(pq.top());
            pq.pop();
        }
    }
    return vec;
}

// You will be given 2 types of queries:-
// 0 X
// Insert X in the heap.
// 1
// Print the minimum element from the heap and remove it.

int main(){
    vector<vector<int>> vec= {
        {0,5},
        {0, 15},
        {1},
        {0, 17},
        {1}
    };
    int n= 5;  //No. of queries is 5.
    vector<int> ans= minHeap(n, vec); //vector containing pop element
    cout<<"Popped element are: ";
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}
