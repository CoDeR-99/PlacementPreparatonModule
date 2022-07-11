#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
 };
 ListNode* head= NULL;

 ListNode* insert(int new_data, ListNode* head) {
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
    return head;
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
    int length(ListNode* head){
        int count=0;
        ListNode* temp= head;
        while(temp){
            count++;
            temp= temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int len= length(head);
        k= k%len;
        if(k==0 || len==k || len==1){
            return head;
        }
        int count= 1;
        k= len-k;
        ListNode* prev= NULL;
        ListNode* temp1= head;
        while(count<=k){
            prev= temp1;
            temp1= temp1->next;
            count++;
        }
        prev->next= NULL;
        ListNode* temp2= temp1;
        while(temp2->next){
            temp2= temp2->next;
        }
        temp2->next= head;
        return temp1;
    }
};

int main(){
    head= insert(1, head);
    head= insert(2, head);
    head= insert(3, head);
    head= insert(4, head);
    head= insert(5, head);
    cout<<"Original Linked List: ";
    display(head);
    Solution obj;
    head= obj.rotateRight(head, 3);
    cout<<"Rotated List: ";
    display(head);
    return 0;
}