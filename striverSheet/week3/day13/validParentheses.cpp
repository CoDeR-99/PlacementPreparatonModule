#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n= s.length();
        if(n%2==1){
            return false;
        }
        stack<char> ch;
        for(int i=0; i<n; i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                ch.push(s[i]);
            }
            else if(s[i]==')'){
                if(ch.empty()){
                    return false;
                }
                if(ch.top() != '('){
                    return false;
                }
                ch.pop();
            }
            else if(s[i]==']'){
                if(ch.empty()){
                    return false;
                }
                if(ch.top() != '['){
                    return false;
                }
                ch.pop();
            }
            else{
                if(ch.empty()){
                    return false;
                }
                if(ch.top() != '{'){
                    return false;
                }
                ch.pop();
            }
        }
        if(!ch.empty()){
            return false;
        }
        return true;
    }
};

int main(){
    string s= "({()()[()]})";
    Solution obj;
    if(obj.isValid(s)){
        cout<<"Valid Parentheses.\n";
    }
    else{
        cout<<"Not valid Parentheses.\n";
    }
    return 0;
}