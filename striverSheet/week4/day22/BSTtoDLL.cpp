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

    void helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &prev, BinaryTreeNode<int>* &head){
    if(root==NULL) return;
    helper(root->left, prev, head);
    if(head==NULL) head= root;
    root->left= prev;
    if(prev!=NULL){
        prev->right= root;
    }
    prev= root;
    helper(root->right, prev, head);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* prev=NULL;
    BinaryTreeNode<int>* head=NULL;
    helper(root, prev, head);
    return head;
}