#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string str= countAndSay(n-1);
        string ans= "";
        int count= 0;
        int size= str.length();
        int i=0;
        while(i<size){
            if(str[i]=='9'){
                while(i<size && str[i]=='9'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '9';
                count= 0;
            }
            else if(str[i]=='8'){
                while(i<size && str[i]=='8'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '8';
                count= 0;
            } 
            else if(str[i]=='7'){
                while(i<size && str[i]=='7'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '7';
                count= 0;
            } 
            else if(str[i]=='6'){
                while(i<size && str[i]=='6'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '6';
                count= 0;
            } 
            else if(str[i]=='5'){
                while(i<size && str[i]=='5'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '5';
                count= 0;
            }
            else if(str[i]=='4'){
                while(i<size && str[i]=='4'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '4';
                count= 0;
            }
            else if(str[i]=='3'){
                while(i<size && str[i]=='3'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '3';
                count= 0;
            } 
            else if(str[i]=='2'){
                while(i<size && str[i]=='2'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '2';
                count= 0;
            }
            else if(str[i]=='1'){
                while(i<size && str[i]=='1'){
                    count++;
                    i++;
                }
                ans+= to_string(count);
                ans+= '1';
                count= 0;
            } 
        }
        return ans;
    }
};

int main(){
    int n= 5;
    Solution obj;
    string ans= obj.countAndSay(n);
    int size= ans.length();
    for(int i=0; i<size; i++){
        cout<<ans[i];
    }
    return 0;
}