#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.length();
        int m= needle.length();
        if(m==0){
            return 0;
        }
        
        for(int i=0; i<n; i++){
            int k=i;
            int j= 0;
            while(j<m && k<n && haystack[k]==needle[j]){
                k++; j++;
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    string haystack= "hello";
    string needle= "ll";
    Solution obj;
    cout<<obj.strStr(haystack, needle);
    return 0;
}