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
    void helper(TreeNode* root, int &count, int k, int &ans){
        if(root==NULL) return;
        helper(root->left, count, k, ans);
        count++;
        if(count==k){
            ans= root->val;
            return;
        }
        helper(root->right, count, k, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count= 0;
        int ans=-1;
        helper(root, count, k, ans);
        return ans;
    }
};
 