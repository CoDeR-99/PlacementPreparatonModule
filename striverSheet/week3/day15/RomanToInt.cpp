#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans= 0;
        int n= s.length();
        map<char, int> mp;
        mp.insert({'I', 1});
        mp.insert({'V', 2});
        mp.insert({'X', 3});
        mp.insert({'L', 4});
        mp.insert({'C', 5});
        mp.insert({'D', 6});
        mp.insert({'M', 7});
        for(int i=0; i<n; i++){
            if(s[i]=='M'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 1000;
                }
                else{
                    ans+= 1000;
                }
            }
            else if(s[i]=='D'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 500;
                }
                else{
                    ans+= 500;
                }
            }
            else if(s[i]=='C'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 100;
                }
                else{
                    ans+= 100;
                }
            }
            else if(s[i]=='L'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 50;
                }
                else{
                    ans+= 50;
                }
            }
            else if(s[i]=='X'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 10;
                }
                else{
                    ans+= 10;
                }
            }
            else if(s[i]=='V'){
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 5;
                }
                else{
                    ans+= 5;
                }
            }
            else{
                if(i+1<n && mp[s[i]]<mp[s[i+1]])
                {
                    ans-= 1;
                }
                else{
                    ans+= 1;
                }
            }
        }
        return ans;
    }
};

int main(){
    string s= "MCMXCIV";
    Solution obj;
    cout<<"Integer value: "<<obj.romanToInt(s);
    return 0;
}