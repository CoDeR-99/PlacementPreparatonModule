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

class BSTIterator {
public:
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        TreeNode* temp= root;
        if(root!=NULL){
            s.push(temp);
            temp= temp->left;
            while(temp){
                s.push(temp);
                temp= temp->left;
            }
        }
    }
    
    int next() {
        TreeNode* temp= s.top();
        s.pop();
        TreeNode* curr= temp->right;
        if(curr!=NULL){
            s.push(curr);
            curr= curr->left;
        }
        while(curr){
            s.push(curr);
            curr= curr->left;
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !(s.empty());
    }
};