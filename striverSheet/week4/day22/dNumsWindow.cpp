#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> dNums(vector<int> &A, int B) {
    int n= A.size();
    vector<int> vec;
    if(n<B){
        return vec;
    }
    map<int, int> mp;
    for(int i=0; i<B; i++){
        mp[A[i]]++;
    }
    vec.push_back(mp.size());
    int j= 0;
    for(int i=B; i<n; i++){
        if(mp[A[j]]>1){
            mp[A[j]]--;
        }
        else{
            mp.erase(A[j]);
        }
        mp[A[i]]++;
        vec.push_back(mp.size());
        j++;
    }
    return vec;
}
};

int main()
{
    vector<int> A= {1, 2, 1, 3, 4, 3};
    int B=3;
    Solution obj;
    vector<int> ans= obj.dNums(A, B);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
