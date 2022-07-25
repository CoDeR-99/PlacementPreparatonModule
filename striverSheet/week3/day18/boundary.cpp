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

    bool isLeaf(TreeNode<int>* root){
    if(root->left==NULL && root->right==NULL){
        return true;
    }
    return false;
}
void addLeft(TreeNode<int> *root, vector<int> &vec){
    TreeNode<int> *temp= root->left;
    while(temp!=NULL){
        if(!isLeaf(temp)) vec.push_back(temp->data);
        if(temp->left!=NULL) temp= temp->left;
        else temp= temp->right;
    }
}
void addRight(TreeNode<int> *root, vector<int> &vec){
    TreeNode<int> *temp= root->right;
    vector<int> v;
    while(temp!=NULL){
        if(!isLeaf(temp)) v.push_back(temp->data);
        if(temp->right!=NULL) temp= temp->right;
        else temp= temp->left;
    }
    for(int i= v.size()-1; i>=0; i--){
        vec.push_back(v[i]);
    }
}
void addLeaves(TreeNode<int> *root, vector<int> &vec){
        if(isLeaf(root)) {
            vec.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, vec);
        if(root->right) addLeaves(root->right, vec);
       
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> vec;
    if(root==NULL){
        return vec;
    }
    if(!isLeaf(root)) vec.push_back(root->data);
    addLeft(root, vec);
    addLeaves(root, vec);
    addRight(root, vec);
    return vec;
}