#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        if(start.length() != target.length()){
            return false;
        }
        int idxs= 0, idxt= 0;
        int ns= start.length();
        int nt= target.length();
        while(idxs<ns || idxt<nt){
            while(idxs<ns && start[idxs]=='_'){
                idxs++;
            }
            while(idxt<nt && target[idxt]=='_'){
                idxt++;
            }
            if(idxs==ns && idxt==nt){
                return true;
            }
            if(idxs==ns || idxt==nt || start[idxs]!=target[idxt]){
                return false;
            }
            if(target[idxt]=='R' && idxs>idxt){
                return false;
            }
            if(target[idxt]=='L' && idxs<idxt){
                return false;
            }
            idxs++; idxt++;
        }
        return true;
    }
};

int main(){
    string s1= "_L__R__R_"; string t1= "L______RR";
    string s2= "R_L_"; string t2= "__LR";
    string s3= "_R"; string t3= "R_";
    Solution obj;
    string ans= (obj.canChange(s1, t1))? "true":"false";
    cout<<ans<<"\n";
    ans= (obj.canChange(s2, t2))? "true":"false";
    cout<<ans<<"\n";
    ans= (obj.canChange(s3, t3))? "true":"false";
    cout<<ans<<"\n";
    return 0;
}