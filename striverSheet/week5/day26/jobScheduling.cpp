#include<bits/stdc++.h>
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b){
        return a.profit > b.profit;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<int> v(2, 0);
        sort(arr, arr+n, comp);
        int maxDay= arr[0].dead;
        for(int i=1; i<n; i++){
            if(maxDay<arr[i].dead){
                maxDay= arr[i].dead;
            }
        }
        vector<int> temp(maxDay, 0);
        int countJob= 0, countProfit= 0;
        for(int i=0; i<n; i++){
            if(temp[arr[i].dead-1]==0){
                temp[arr[i].dead-1]= 1;
                countProfit+= arr[i].profit;
                countJob++;
            }
            else{
                int j= arr[i].dead-2;
                while(j>=0){
                    if(temp[j]==0){
                        temp[j]= 1;
                        countProfit+= arr[i].profit;
                        countJob++;
                        break;
                    }
                    j--;
                }
            }
        }
        v[0]= countJob; v[1]= countProfit;
        return v;
    }
};

int main(){
    int N=4;
    Job arr[4];
    arr[0].dead= 4;
    arr[0].id= 1;
    arr[0].profit= 20;

    arr[1].dead= 1;
    arr[1].id= 2;
    arr[1].profit= 10;

    arr[2].dead= 1;
    arr[2].id= 3;
    arr[2].profit= 40;

    arr[3].dead= 1;
    arr[3].id= 4;
    arr[3].profit= 30;

    Solution obj;
    vector<int> ans= obj.JobScheduling(arr, N);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}