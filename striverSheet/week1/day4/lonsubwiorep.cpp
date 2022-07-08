#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int l= 0;
        int ans= 0;
        unordered_set<char> mp;
        for(int j=0; j<s.length(); j++){
            if(mp.find(s[j]) != mp.end()){
                while(l<j && mp.find(s[j])!=mp.end()){
                    mp.erase(s[l]);
                    l++;
                }
            }
            mp.insert(s[j]);
            ans= max(ans, j-l+1);
        }
        return ans;
    }
};

int main(){
    Solution obj;
    string s= "abcabcbb";
    cout<<obj.lengthOfLongestSubstring(s);
    return 0;
}