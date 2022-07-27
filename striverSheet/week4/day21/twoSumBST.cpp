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
    stack<TreeNode*> s1;  //smallest to greater
    stack<TreeNode*> s2;  //greater to smallest
    void helper(TreeNode* root) {
        TreeNode* temp1= root;
        TreeNode* temp2= root;
        if(root!=NULL){
            s1.push(temp1);
            s2.push(temp2);
            temp1= temp1->left;
            temp2= temp2->right;
            while(temp1){
                s1.push(temp1);
                temp1= temp1->left;
            }
            while(temp2){
                s2.push(temp2);
                temp2= temp2->right;
            }
        }
    }
    
    TreeNode* nextIncreasing() {
        TreeNode* temp= s1.top();
        s1.pop();
        TreeNode* curr= temp->right;
        if(curr!=NULL){
            s1.push(curr);
            curr= curr->left;
        }
        while(curr){
            s1.push(curr);
            curr= curr->left;
        }
        return temp;
    }
    TreeNode* nextDecreasing() {
        TreeNode* temp= s2.top();
        s2.pop();
        TreeNode* curr= temp->left;
        if(curr!=NULL){
            s2.push(curr);
            curr= curr->right;
        }
        while(curr){
            s2.push(curr);
            curr= curr->right;
        }
        return temp;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL || (root->left==NULL && root->right==NULL)){
            return false;
        }
        helper(root);
        TreeNode* i= nextIncreasing();
        TreeNode* j= nextDecreasing();
        while(i!=j){
            if(i->val+j->val==k){
                return true;
            }
            else if(i->val+j->val > k){
                j= nextDecreasing();
            }
            else{
                i= nextIncreasing();
            }
        }
        return false;
    }
};