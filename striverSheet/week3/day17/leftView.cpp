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

void helper(TreeNode<int> *root, vector<int> &vec, int level){
    if(root==NULL){
        return;
    }
    if(level==vec.size()){
        vec.push_back(root->data);
    }
    helper(root->left, vec, level+1);
    helper(root->right, vec, level+1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> vec;
    helper(root, vec, 0);
    return vec;
}