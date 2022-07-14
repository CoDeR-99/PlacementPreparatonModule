#include<bits/stdc++.h>
using namespace std;

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int ans= 1;
    int count= 1;
    sort(at, at+n);
    sort(dt, dt+n);
    int a= 1, d= 0;
    while(a<n){
        if(at[a]<=dt[d]){
            count++;
            ans= max(ans, count);
            a++;
        }
        else{
            count--;
            d++;
        }
    }
    return ans;
}

int main(){
    int start[]= {900, 940, 950, 1100, 1500, 1800};
    int end[]= {910, 1200, 1120, 1130, 1900, 2000};
    int n=6;
    cout<<"Maximun required platform: "<<calculateMinPatforms(start, end, 6);
    return 0;
}