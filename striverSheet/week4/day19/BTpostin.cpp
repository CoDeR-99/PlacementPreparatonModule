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
    TreeNode* buildTree(vector<int> &postorder, int ps, int pe, vector<int> &inorder, int is, int ie, map<int, int> &mp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root= new TreeNode(postorder[pe]);
        int mid= mp[postorder[pe]];
        int ele= mid-is;
        root->left= buildTree(postorder, ps, ps+ele-1, inorder, is, mid-1, mp);
        root->right= buildTree(postorder, ps+ele, pe-1, inorder, mid+1, ie, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]= i;
        }
        TreeNode *root= buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};