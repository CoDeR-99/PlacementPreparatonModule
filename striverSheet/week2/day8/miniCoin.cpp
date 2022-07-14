#include<bits/stdc++.h>
using namespace std;

    int helper(int coins[], int M, int V){
	    int table[V+1];
	    table[0]= 0;
	    
	    for(int i=1; i<=V; i++){
	        table[i]= INT_MAX;
	    }
	    
	    for(int i=1; i<=V; i++){
	        for(int j=0; j<M; j++){
	        if(coins[j]<=i){
	            int sub_res= table[i-coins[j]];
	            
	            if(sub_res != INT_MAX && sub_res+1<table[i]){
	                table[i]= sub_res+1;
	            }
	        }
	        }
	    }
	    return table[V];
	}

	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    int r= helper(coins, M, V);
	    if(r==INT_MAX) return -1;
	    return r;
	} 

    int main(){
        int coins[]= {9, 6, 5, 1};
        int M= 4; int V= 11;
        cout<<"Minimum coins: "<<minCoins(coins, M, V);
        return 0;
    }