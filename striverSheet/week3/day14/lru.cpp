#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node *prev, *next;
        Node(int k, int v){
            key= k;
            val= v;
            prev= NULL;
            next= NULL;
        }
    };
    Node *head= new Node(-1,-1);
    Node *tail= new Node(1,-1);
    int cap;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap= capacity;
        head->next= tail;
        tail->prev= head;
    }
    
    void add(Node* newnode){
        Node* temp= head->next;
        head->next= newnode;
        temp->prev= newnode;
        newnode->prev= head;
        newnode->next= temp;
    }
    
    void del(Node* newnode){
        Node* delprev= newnode->prev;
        Node* delnext= newnode->next;
        delprev->next= delnext;
        delnext->prev= delprev;
    }
    
    int get(int k) {
        if(mp.find(k) != mp.end()){
            Node *temp= mp[k];
            mp.erase(k);
            int value= temp->val;
            del(temp);
            add(temp);
            mp[k]= head->next;
            return value;
        }
        else{
            return -1;
        }
    }
    
    void put(int k, int value) {
        if(mp.find(k) != mp.end()){
            Node* existingnode = mp[k]; 
            mp.erase(k); 
            del(existingnode);
        }
        if(mp.size()==cap){
             mp.erase(tail->prev->key);
            del(tail->prev);
        }
        
        add(new Node(k, value)); 
        mp[k] = head->next; 
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */