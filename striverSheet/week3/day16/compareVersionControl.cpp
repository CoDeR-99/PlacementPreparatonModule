#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l1= version1.length(); int l2= version2.length();
        int i=0, j=0;
        int n1, n2;
        while(i<l1 || j<l2){
            n1= 0;
            n2= 0;
            while(i<l1 && version1[i]!='.'){
                n1= (n1*10)+(version1[i]-'0');
                i++;
            }
            while(j<l2 && version2[j]!='.'){
                n2= (n2*10)+(version2[j]-'0');
                j++;
            }
            if(n1>n2) return 1;
            if(n1<n2) return -1;
            i++;
            j++;
        }
        return 0;
    }
};

int main(){
    string version1= "00.1.0";
    string version2= "00.10.0";
    Solution obj;
    cout<<obj.compareVersion(version1, version2);
    return 0;
}