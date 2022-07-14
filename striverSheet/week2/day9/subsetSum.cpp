#include<bits/stdc++.h>
using namespace std;

    void helper(int i, vector<int> &arr, int n, vector<int> &ans, int sum){
        if(i==n){
            ans.push_back(sum);
            return;
        }
        helper(i+1, arr, n, ans, sum+arr[i]);
        helper(i+1, arr, n, ans, sum);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        helper(0, arr, N, ans, 0);
        return ans;
    }

int main(){
    int N= 3;
    vector<int> arr= {5, 2, 1};
    vector<int> vec= subsetSums(arr, N);
    sort(vec.begin(), vec.end());
    for(auto x: vec){
        cout<<x<<" ";
    }
    return 0;
}