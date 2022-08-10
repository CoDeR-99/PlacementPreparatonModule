#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum= 0;
        int n= nums.size();
        for(int i=0; i<n; i++){
            sum+= nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int target= sum/2;
        set<int> s;
        for(int i= nums.size()-1; i>=0; i--){
            if(s.empty()){
                s.insert(0);
                s.insert(nums[i]);
            }
            else{
                set<int>::iterator itr;
                vector<int> vec;
                for (itr = s.begin(); itr != s.end(); itr++){
                    vec.push_back((*itr));
                }
                for(int k=0; k<vec.size(); k++){
                    int temp= vec[k]+nums[i];
                    if(temp==target){
                        return true;
                    }
                    else{
                        s.insert(temp);
                    }
                }
            }
            
        }
        return false;
    }
};

int main(){
    vector<int> vec= {1, 5, 11, 5};
    Solution obj;
    cout<<obj.canPartition(vec);
    return 0;
}