#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    vector<int> temp(n, 0);
    for(int i=0; i<n; i++){
        temp[arr[i]-1]++;
    }
    pair<int, int> p;
    for(int i=0; i<n; i++){
        if(temp[i]==0){
            p.first= i+1;
        }
        if(temp[i]==2){
            p.second= i+1;
        }
    }
	return p;
}

int main(){
    vector<int> vec= {1, 4, 2, 1, 3};
    cout<<"("<<missingAndRepeating(vec, 5).first << ", " <<missingAndRepeating(vec, 5).second<<")";
    return 0;
}