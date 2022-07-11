#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node* r1, Node* r2){
    // cout<<r1->data<<" "<<r2->data<<"\n";
    Node* root= r1;
    if(r1->data > r2->data){
        swap(r1, r2);
        root= r1;
        // cout<<r1->data<<" "<<r2->data<<"\n";
    }
    Node* l1= r1;
    Node* l2= r2;
    Node* prev= NULL;
    while(l1!=NULL && l2!=NULL){
        if(l1->data <= l2->data){
            prev= l1;
            l1= l1->bottom;
        }
        else{
            prev->bottom= l2;
            swap(l1, l2);
        }
    }
    prev->bottom= l2;
    return root;
}

Node *flatten(Node *root)
{
   // Your code here
   if(root==NULL || root->next==NULL){
       return root;
   }
   Node* temp= root;
   while(temp!= NULL && temp->next != NULL){
       if(temp->next->next!=NULL){
           Node* t= temp->next->next;
           temp= merge(temp, temp->next);
           temp->next= t;
       }
       else{
           temp =merge(temp, temp->next);
           temp->next= NULL;
       }
   }
   return temp;
}

