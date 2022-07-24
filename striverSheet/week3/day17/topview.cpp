#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> vec;
    if(root==NULL){
        return vec;
    }
    map<int , int> mp; //<verticalLevel, data>
    queue<pair<TreeNode<int>*, int>> q; //<node, verticalLevel>
    q.push({root, 0});
    while(!q.empty()){
        pair<TreeNode<int>*, int> p= q.front();
        q.pop();
        if(p.first->left != NULL) q.push({p.first->left, p.second-1});
        if(p.first->right != NULL) q.push({p.first->right, p.second+1});
        mp.insert({p.second, p.first->val}); /*if element already present it does not add so always the first element at each vertical will be added*/
    }
    for(auto x: mp){
        vec.push_back(x.second);
    }
    return vec;
}