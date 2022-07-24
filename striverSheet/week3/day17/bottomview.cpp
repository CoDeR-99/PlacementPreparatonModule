#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> vec;
    if(root==NULL){
        return vec;
    }
    map<int, int> mp; //<vertical line, nodeValue>
    queue<pair<BinaryTreeNode<int>*, int>> q; //<node, vertical line>
    q.push({root, 0});
    while(!q.empty()){
        pair<BinaryTreeNode<int>*, int> p= q.front();
        q.pop();
        if(p.first->left != NULL) q.push({p.first->left, p.second-1});
        if(p.first->right != NULL) q.push({p.first->right, p.second+1});
        mp[p.second]= p.first->data;
    }
    for(auto x: mp){
        vec.push_back(x.second);
    }
    return vec;
}
