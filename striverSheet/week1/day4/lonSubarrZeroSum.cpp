#include <bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector < int > arr) {
    if(arr.size()==0){
        return 0;
    }
  map<int, int> mp;
    int ans=0, sum= 0;
    int i;
    mp.insert({sum, -1});
  for(i=0; i<arr.size(); i++){
      sum+= arr[i];
      if(mp.find(sum) == mp.end()){
          mp.insert({sum, i});
      }
      else{
          ans= max(ans, i-mp[sum]);
      }
  }
    
    return ans;
}

int main()
{
    vector<int> nums= {1, -1, 2,
     -2 };
    cout<<LongestSubsetWithZeroSum(nums);
    return 0;
}