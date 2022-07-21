#include<bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s)
{
	// Write your code here
    stack<int> s1;
    stack<int> s2;
    while(!s.empty()){
        if(s1.empty()){
            s1.push(s.top());
            s.pop();
        }
        else{
            if(s.top() <= s1.top()){
                s1.push(s.top());
                s.pop();
            }
            else{
                while(!s1.empty() && s.top()>s1.top()){
                    s2.push(s1.top());
                    s1.pop();
                }
                s1.push(s.top());
                s.pop();
                while(!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
        }
    }
    while(!s1.empty()){
        s.push(s1.top());
        s1.pop();
    }
}

int main(){
    stack<int> sk;
    return 0;
}