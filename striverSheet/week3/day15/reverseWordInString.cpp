#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n= s.length();
        if(n==0 || n==1){
            return s;
        }
        //remove trailing spaces
        int i=0, j=n-1;
        while(i<n && s[i]==' '){
            i++;
        }
        while(j>=0 && s[j]==' '){
            j--;
        }
        s= s.substr(i,j-i+1);

        //remove extra spaces in between
        string str= "";
        i=0; n= s.length(); //length changes after removing spaces.
        while(i<n){
            if(s[i] != ' '){
                str+= s[i];
                i++;
            }
            else{
                str+= s[i];
                while(i<n && s[i]==' '){
                    i++;
                }
            }
        }
        s= str;
        reverse(s.begin(), s.end());
        i=0, j=1; n= s.length();
        while(j<n){
            if(s[j]==' '){
                reverse(s.begin()+i, s.begin()+j);
                i= j+1;
            }
            j++;
        }
        reverse(s.begin()+i, s.begin()+j);
        return s;
    }
};

int main(){
    string s= "the     sky is blue    ";
    Solution obj;
    cout<<"$"<<obj.reverseWords(s)<<"$";
    return 0;
}