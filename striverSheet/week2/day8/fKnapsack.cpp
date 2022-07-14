#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, [](Item a,Item b){return (a.value*b.weight)>(b.value*a.weight);});
        double profit= 0;
        int i=0;
        while(i<n && W>0){
            if(W-arr[i].weight>=0){
                profit+= arr[i].value;
                W-= arr[i].weight;
            }
            else{
                profit+= W * ((double)arr[i].value/(double)arr[i].weight);
                W=0;
            }
            i++;
        }
        return profit;
    }
        
};

int main(){
    Item arr[3];
    arr[0].value= 60; arr[0].weight= 10;
    arr[1].value= 100; arr[1].weight= 20;
    arr[2].value= 120; arr[2].weight= 30;
    int W= 50;
    Solution obj;
    cout<<"Maximum profit: "<<obj.fractionalKnapsack(W, arr, 3);
    return 0;
}