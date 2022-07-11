#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
 };
ListNode* head= NULL;

void insert(int new_data) {
    ListNode* newNode= new ListNode();
    newNode->val= new_data;
    newNode->next= NULL;
    if(head==NULL){
        head= newNode;
    }
    else{
        ListNode* temp= head;
        while(temp->next != NULL){
            temp= temp->next;
        }
   temp->next= newNode;
    }
}

void display(ListNode* Head) {
   ListNode* ptr;
   ptr = Head;
   while (ptr != NULL) {
      cout<< ptr->val <<" ";
      ptr = ptr->next;
   }
   cout<<"\n";
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return head;
        }
        int count= 0;
        ListNode* temp= head;
        while(temp != NULL){
            count++;
            temp= temp->next;
        }
        int size= count;
        count= count-n+1;
        if(size==1 && n==1){
            return NULL;
        }
        if(size==n){
            return head->next;
        }
        temp= head;
        ListNode* prev;
        while(1){
            if(count==1){
                break;
            }
            prev= temp;
            temp= temp->next;
            count--;
        }
        prev->next= temp->next;
        return head;
    }
};

int main(){
    insert(7);
    insert(6);
    insert(9);
    insert(4);
    insert(13);
    insert(2);
    insert(8);
    int x= 6;
    cout<<"Original linked list: ";
    display(head);
    Solution obj;
    head= obj.removeNthFromEnd(head, x);
    cout<<"linked list after deletion: ";
    display(head);
    return 0;
}