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
    bool helper(TreeNode* root, long long s, long long e){
        if(root==NULL){
            return true;
        }
        bool left= helper(root->left, s, (long long)root->val-1);
        bool right= helper(root->right, (long long)root->val+1, e);
        if(left && right){
            if(root->val>=s && root->val<=e){
                return true;
            }
            return false;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};