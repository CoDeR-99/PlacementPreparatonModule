#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int res= 0;
        int left= 0, right= n-1;
        int leftMax= 0, rightMax= 0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>leftMax)
                    leftMax= height[left];
                else
                    res+= leftMax-height[left];
                left++;
            }
            else{
                if(height[right]>rightMax)
                    rightMax= height[right];
                else
                    res+= rightMax-height[right];
                right--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> vec= {4, 2, 0, 3, 2, 5};
    Solution obj;
    int ans= obj.trap(vec);
    cout<<"Rainwater trapped: "<<ans;
    return 0;
}