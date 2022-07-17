#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> position, int n, int c, int mid){
    int placed= position[0];
    int count= 1;
    for(int i=1; i<n; i++){
        if(position[i]-placed >= mid){
            count++;
            placed= position[i];
        }
        if(count>=c){
            return true;
        }
    }
    return false;
}

int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    int low= 0;
    int high= positions[n-1];
    int res= -1;
    while(low<=high){
        int mid= low+(high-low)/2;
        if(isPossible(positions, n, c, mid)){
            res= mid;
            low= mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return res;
}

int main(){
    vector<int> vec= {6, 7, 9, 13, 15, 11};
    int size= 6;
    int cow= 4;
    cout<<"Largest minimum possible distance: "<<chessTournament(vec, size, cow);
    return 0;
}