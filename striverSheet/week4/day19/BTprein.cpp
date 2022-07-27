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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]= i;
        }
        TreeNode *root= buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root= new TreeNode(preorder[ps]);
        int mid= mp[preorder[ps]];
        int ele= mid-is;
        root->left= buildTree(preorder, ps+1, ps+ele, inorder, is, mid-1, mp);
        root->right= buildTree(preorder, ps+ele+1, pe, inorder, mid+1, ie, mp);
        return root;
    }
};