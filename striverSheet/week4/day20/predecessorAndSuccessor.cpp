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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int successor= -1;
    BinaryTreeNode<int>* curr= root;
    while(curr){
        if(curr->data <= key){
            curr= curr->right;
        }
        else{
            successor= curr->data;
            curr= curr->left;
        }
    }
    curr= root;
    int predecessor= -1;
    while(curr){
        if(curr->data >= key){
            curr= curr->left;
        }
        else{
            predecessor= curr->data;
            curr= curr->right;
        }
    }
    pair<int, int> p= {predecessor, successor};
    return p;
}
