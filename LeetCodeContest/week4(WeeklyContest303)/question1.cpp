#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        map<char, int> mp;
        char c;
        for(int i=0; i<s.length(); i++){
            mp[s[i]]++;
            if(mp[s[i]]==2){
                c= s[i];
                break;
            }
        }
        return c;
    }
};

int main(){
    string s= "abccbaacz";
    Solution obj;
    cout<<obj.repeatedCharacter(s);
}