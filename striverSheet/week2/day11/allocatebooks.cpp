#include<bits/stdc++.h>
using namespace std;

bool isPossible(int n, int m, vector<int> vec,long long int mid){
    int day= 1;
    long long int sum= 0;
    for(int i=0; i<m; i++){
        if(sum+vec[i]<=mid){
            sum+= vec[i];
        }
        else{
            day++;
            if(day>n || vec[i]>mid){
                return false;
            }
            sum= vec[i];
        }
    }
    return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    long long low= 0;
    long long int high= 0;
    for(int i=0; i<m; i++){
        high+= time[i];
    }
    long long int ans= -1;
    while(low<=high){
        long long int mid= low + (high-low)/2;
        if(isPossible(n, m, time, mid)){
            ans= mid;
            high= mid-1;
        }
        else{
            low= mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> vec= {1, 2, 2, 3, 1};
    int n= 3;
    int size= 5;
    cout<<"Minimum allocation of days: "<<ayushGivesNinjatest(n, size, vec);
    return 0;
}