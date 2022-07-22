#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> vec(n);
    for(int i=0; i<n; i++){
        vec[i]= -1;
    }
    if(n==1){
        return vec;
    }
    stack<pair<int, int>> s;
    s.push({arr[0], 0});
    for(int i=1; i<n; i++){
        if(arr[i]>=s.top().first){
            s.push({arr[i], i});
        }
        else{
            while(!s.empty() && arr[i]<s.top().first){
                vec[s.top().second]= arr[i];
                s.pop();
            }
            s.push({arr[i], i});
        }
    }
    return vec;
}

int main(){
    vector<int> vec= {2, 1, 4, 3};
    int n= vec.size();
    vector<int> ans= nextSmallerElement(vec, n);
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}