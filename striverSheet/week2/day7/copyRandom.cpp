#include<bits/stdc++.h>
using namespace std;

struct Node {
      int val;
      Node *next;
      Node* random;
      Node(int v){
        val= v;
        next= NULL;
        random= NULL;
      }
 };
 Node* head= NULL;

 class Solution {
public:
    Node* insert(int new_data, Node* head) {
    Node* newNode= new Node(new_data);
    if(head==NULL){
        head= newNode;
    }
    else{
        Node* temp= head;
        while(temp->next != NULL){
            temp= temp->next;
        }
   temp->next= newNode;
    }
    return head;
}
    Node* insertRandom(int count, Node* head){
        Node* temp= head;
        while(count){
            temp= temp->next;
            count--;
        }
        return temp;
    }
    
    Node* copyRandomList(Node* head) {
        Node* Head= NULL;
        Node* temp= head;
        while(temp){
            Head= insert(temp->val, Head);
            temp= temp->next;
        }
        Node* temp1= head;
        Node* temp2= Head;
        while(temp1){
            if(temp1->random==NULL){
                temp2->random= NULL;
            }
            else{
                int count= 0;
                Node* t= temp1->random;
                Node* p= head;
                while(p != t){
                    count++;
                    p= p->next;
                }
                temp2->random= insertRandom(count, Head);
            }
            temp1= temp1->next;
            temp2= temp2->next;
        }
        return Head;
    }
};