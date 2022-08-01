#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    double median;
    MedianFinder() {
        median= 0;
    }
    
    void addNum(int num) {
        if(q1.size()==q2.size()){
            if(num < median){
                q1.push(num);
                median= q1.top();
            }
            else{
                q2.push(num);
                median= q2.top();
            }
        }
        else if(q1.size()>q2.size()){
            if(num < median){
                q1.push(num);
                int t= q1.top();
                q1.pop();
                q2.push(t);
            }
            else{
                q2.push(num);
            }
            median= ((double)q1.top()+(double)q2.top())/(double)2;
        }
        else{
            if(num < median){
                q1.push(num);
            }
            else{
                q2.push(num);
                int t= q2.top();
                q2.pop();
                q1.push(t);
            }
            median= ((double)q1.top()+(double)q2.top())/(double)2;
        }
    }
    
    double findMedian() {
        return median;
    }
};
