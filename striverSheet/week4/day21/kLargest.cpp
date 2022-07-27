#include<bits/stdc++.h>
using namespace std;

template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            data = val;
            left = NULL;
            right = NULL;
        }
    };

    #include<bits/stdc++.h>
void helper(TreeNode<int>* root,priority_queue<int, vector<int>, greater<int>> &q, int k){
    if(root==NULL) return;
    helper(root->left, q, k);
    q.push(root->data);
    if(q.size()>k){
        q.pop();
    }
    helper(root->right, q, k);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    priority_queue<int, vector<int>, greater<int>> q;
    helper(root, q, k);
    if(q.size()<k){
        return -1;
    }
    return q.top();
}
