#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, int> mp;
        int nk= key.length();
        int j= 0;
        for(int i=0; i<nk; i++){
            if(mp.find(key[i]) != mp.end() || key[i]==' '){
                continue;
            }
            else{
                mp[key[i]]= j;
                j++;
            }
        }
        string ans= "";
        int nm= message.length();
        for(int i=0; i<nm; i++){
            if(message[i]== ' '){
                ans+= ' ';
            }
            else{
                ans+= char('a' + mp[message[i]]);
            }
        }
        return ans;
    }
};

int main(){
    string key= "eljuxhpwnyrdgtqkviszcfmabo";
    string message= "zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    Solution obj;
    string ans= obj.decodeMessage(key, message);
    cout<<ans;
    return 0;
}