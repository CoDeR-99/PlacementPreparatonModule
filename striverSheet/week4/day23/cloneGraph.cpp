#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    void dfs(Node* x, Node* newnode, vector<Node*> &visited){
        visited[newnode->val]= newnode;
        for(auto y: x->neighbors){
            if(visited[y->val]==NULL){
                Node* n= new Node(y->val);
                newnode->neighbors.push_back(n);
                dfs(y, n, visited);
            }
            else{
                newnode->neighbors.push_back(visited[y->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        vector<Node* > visited(200, NULL);
        Node* copy= new Node(node->val);
        visited[node->val]= copy;
        for(auto x: node->neighbors){
            if(visited[x->val]==NULL){
                Node* newnode= new Node(x->val);
                copy->neighbors.push_back(newnode);
                dfs(x, newnode, visited);
            }
            else{
                copy->neighbors.push_back(visited[x->val]);
            }
        }
        return copy;
    }
};