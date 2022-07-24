#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

    int height(TreeNode<int> *root){
    if(root==NULL){
        return 0;
    }
    int l= height(root->left)+1;
    int r= height(root->right)+1;
    return max(l, r);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(root==NULL){
        return 0;
    }
    int lefth, righth;
    int ans= 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int> *temp= q.front();
        q.pop();
        lefth= height(temp->left);
        righth= height(temp->right);
        ans= max(ans, lefth+righth);
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    
    return ans;;
}
