#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int msis[n];
	    for(int i=0; i<n; i++){
	        msis[i]= arr[i];
	    }
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++){
	            if(arr[j]<arr[i] && msis[i] < arr[i]+msis[j]){
	                msis[i]= arr[i]+msis[j];
	            }
	        }
	    }
	    int max= -1;
	    for(int i=0; i<n; i++){
	        if(max<msis[i]){
	            max= msis[i];
	        }
	    }
	    return max;
	} 
};

int main(){
    int arr[] = {1, 101, 2, 3, 100};
    int n= 5;
    Solution obj;
    cout<<obj.maxSumIS(arr, n); 
    return 0;
}

