#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans= 0;
        int mini= INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(mini > prices[i]){
                mini= prices[i];
            }
            if(prices[i]-mini>ans){
                ans= prices[i]-mini;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int> vec= {7,1,5,3,6,4};
    cout<<obj.maxProfit(vec);
    return 0;
}