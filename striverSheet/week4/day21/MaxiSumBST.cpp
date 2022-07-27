#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
   vector<int>solve(TreeNode *root,int &mxSum){
        vector<int>ans;
        if(!root){
            ans.push_back(INT_MIN);
            ans.push_back(INT_MAX);
        
            ans.push_back(0);
            return ans;
        }
        vector<int>lh;
        vector<int>rh;
        lh=solve(root->left,mxSum);
        rh=solve(root->right,mxSum);
        if(lh[0]<root->val && root->val<rh[1]){
           
            ans.push_back(max(root->val,rh[0]));
            ans.push_back(min(lh[1],root->val));
            ans.push_back(rh[2]+lh[2]+root->val);
            mxSum=max(mxSum,rh[2]+lh[2]+root->val);
        }
        else{
            ans.push_back(INT_MAX);
            ans.push_back(INT_MIN);
            ans.push_back(max(lh[2],rh[2]));
        }
        return ans;
    }
 
    int maxSumBST(TreeNode* root) {
        vector<int>ans;
        int mxSum=0;
        ans=solve(root,mxSum);
    	return mxSum;
    }
};