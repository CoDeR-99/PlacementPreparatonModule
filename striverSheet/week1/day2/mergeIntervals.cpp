#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> vec;
        if(intervals.size()==0){
            return vec;
        }
        sort(intervals.begin(), intervals.end());
        vec.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            int N= vec.size();
            if(vec[N-1][1]>=intervals[i][0]){
                vec[N-1][1]= max(vec[N-1][1], intervals[i][1]);
            }
            else{
                vec.push_back(intervals[i]);
            }
        }
        return vec;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> vec= {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans= obj.merge(vec);
    for(int i=0; i<ans.size(); i++){
        cout<<"("<<ans[i][0]<<", "<<ans[i][1]<<") ";
    }
    return 0;
}