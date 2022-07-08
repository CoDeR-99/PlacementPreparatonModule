#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        else if(n>0){
            if(n%2==0){
            return myPow(x*x, n/2);
        }
        return x*myPow(x, n-1);
        }
        else{
            if(n%2==0){
                return myPow(x*x, n/2);
            }
            return (1/x)*myPow(x,n+1);
        }
    }
};

int main(){
    Solution obj;
    cout<<obj.myPow(4, -3);
    return 0;
}