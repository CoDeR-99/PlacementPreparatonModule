#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i=0; i<3; i++){
            pq.push(amount[i]);
        }
        int ans= 0;
        while(pq.top()!=0){
            int a= pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            a--;
            if(b!=0){
                b--;
            }
            ans++;
            pq.push(a);
            pq.push(b);
        }
        return ans;
    }
};

int main(){
    vector<int> v1= {1, 4, 2};
    vector<int> v2= {5, 4, 4};
    vector<int> v3= {5, 0, 0};
    Solution obj;
    cout<<obj.fillCups(v1)<<"\n";
    cout<<obj.fillCups(v2)<<"\n";
    cout<<obj.fillCups(v3)<<"\n";
    return 0;
}