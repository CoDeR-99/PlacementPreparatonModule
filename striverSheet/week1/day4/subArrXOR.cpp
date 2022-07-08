#include <bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    if(arr.size()==0){
        return 0;
    }
    int n= arr.size();
    int xorr= 0, count= 0;
    unordered_map<int, int> mp;
    for(int i=0; i<n; i++){
        xorr= xorr^arr[i];
        if(xorr==x){
            count++;
        }
        int temp= xorr^x;
        if(mp.find(temp)!=mp.end()){
            count+= mp[temp];
        }
        mp[xorr]++;
    }
    return count;
}

int main(){
    vector<int> vec1= {5, 3, 8, 3, 10};
    int target1= 8;
    vector<int> vec2= {5, 2, 9};
    int target2= 7;
    cout<<subarraysXor(vec1, target1)<<"\n";
    cout<<subarraysXor(vec2, target2);
    return 0;
}