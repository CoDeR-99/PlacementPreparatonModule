#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    BinaryTreeNode<int> *curr= node;
    int s= -1;
    while(curr){
        if(curr->data < x){
            curr= curr->right;
        }
        else if(curr->data==x){
            return curr->data;
        }
        else{
            s= curr->data;
            curr= curr->left;
        }
    }
    return s;
}