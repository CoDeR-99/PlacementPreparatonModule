#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int len= grades.size();
        return ((-1 + sqrt(1+8*len))/2);
    }
};

int main(){
    vector<int> nums= {10,6,12,7,3,5};
    Solution obj;
    cout<<obj.maximumGroups(nums);
    return 0;
}