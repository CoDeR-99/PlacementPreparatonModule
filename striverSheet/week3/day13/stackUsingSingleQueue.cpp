#include<bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> pq;
    MyStack() {
        
    }
    
    void push(int x) {
        pq.push(x);
        int n= pq.size();
        for(int i=1; i<=n-1; i++){
            int temp= pq.front();
            pq.pop();
            pq.push(temp);
        }
    }
    
    int pop() {
        int temp= pq.front();
        pq.pop();
        return temp;
    }
    
    int top() {
        return pq.front();
    }
    
    bool empty() {
        return pq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */