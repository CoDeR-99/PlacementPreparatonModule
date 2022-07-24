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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<TreeNode*, unsigned int>> q; //<node, indexingOfNode>
        q.push({root, 0});
        unsigned int ans= 0;
        while(!q.empty()){
            int n= q.size();
            ans= max(ans, ((q.back().second)-(q.front().second)+1));
            for(int i=0; i<n; i++){
                pair<TreeNode*,unsigned int> p= q.front();
                q.pop();
                if(p.first->left != NULL){
                    q.push({p.first->left, 2*p.second});
                }
                if(p.first->right != NULL){
                    q.push({p.first->right, 2*p.second+1});
                }
            }
        }
        return ans;
    }
};