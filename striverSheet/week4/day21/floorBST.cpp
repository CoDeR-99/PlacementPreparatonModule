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

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    TreeNode<int> *curr= root;
    int predecessor= -1;
    while(curr){
        if(curr->val > X){
            curr= curr->left;
        }
        else if(curr->val==X){
            return curr->val;
        }
        else{
            predecessor= curr->val;
            curr= curr->right;
        }
    }
    return predecessor;
}