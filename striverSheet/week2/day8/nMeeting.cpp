#include<bits/stdc++.h>
using namespace std;

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        if(n==0){
            return 0;
        }
        vector<vector<int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({end[i], start[i]});
        }
        sort(vec.begin(), vec.end());
        int count= 1;
        int endp= vec[0][0];
        for(int i=1; i<n; i++){
            if(vec[i][1]>endp){
                count++;
                endp= vec[i][0];
            }
        }
        return count;
    }

int main(){
    int start[]= {1,3,0,5,8,5};
    int end[]= {2,4,6,7,9,9};
    int n=6;
    cout<<"Maximun meeting that can be held: "<<maxMeetings(start, end, 6);
    return 0;
}