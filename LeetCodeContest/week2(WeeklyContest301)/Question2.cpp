#include<bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, int> mp;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++){
            pq.push(i);
            mp.insert({i, 1});
        }
    }
    
    int popSmallest() {
        int n= pq.top();
        pq.pop();
        mp.erase(n);
        return n;
    }
    
    void addBack(int num) {
        if(mp.find(num) != mp.end()){
            return;
        }
        pq.push(num);
        mp.insert({num, 1});
    }
};

int main(){
    return 0;
}