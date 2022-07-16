#include<bits/stdc++.h>
using namespace std;

double multiply(double x, int n){
    double ans= 1.00;
    for(int i=0; i<n; i++){
        ans= ans*x;
    }
    return ans;
}
double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double low= 0;
    double high= m+1;
    double eps= 1e-8;
    while((high-low)>eps){
        double mid= (low+high)/2.00;
        if(multiply(mid, n)<(double)m){
            low= mid;
        }
        else{
            high= mid;
        }
    }
    return low;
}


int main(){
    int n =3;
    long long m= 7;
    cout<<findNthRootOfM(n, m);
    return 0;
}