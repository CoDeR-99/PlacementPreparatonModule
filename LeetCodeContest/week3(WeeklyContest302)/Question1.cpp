#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int a= 0, b= 0;
        map<int, int> mp;
        int n= nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(auto x: mp){
            a+= x.second/2;
            b+= x.second%2;
        }
        vector<int> vec(2);
        vec[0]= a;
        vec[1]= b;
        return vec;
    }
};

int main(){
    vector<int> v1= {1,3,2,1,3,2,2};
    vector<int> v2= {1,1};
    vector<int> v3= {0};
    Solution obj;
    cout<<obj.numberOfPairs(v1)[0]<<" "<<obj.numberOfPairs(v1)[1]<<"\n";
    cout<<obj.numberOfPairs(v2)[0]<<" "<<obj.numberOfPairs(v2)[1]<<"\n";
    cout<<obj.numberOfPairs(v3)[0]<<" "<<obj.numberOfPairs(v3)[1]<<"\n";
    return 0;
}