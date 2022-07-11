#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry= 0;
        ListNode* head= NULL;
        ListNode* tail= NULL;
        ListNode* temp1= l1;
        ListNode* temp2= l2;
        while(temp1 != NULL && temp2 != NULL){
            int n= temp1->val+temp2->val+carry;
            carry= n/10;
            ListNode* newNode= new ListNode();
            newNode->val= n%10;
            if(head==NULL){
                head= newNode;
                tail= newNode;
            }
            else{
                tail->next= newNode;
                tail= newNode;
            }
            temp1= temp1->next;
            temp2= temp2->next;
        }
        while(temp1 != NULL){
            int n= temp1->val+carry;
            carry= n/10;
            ListNode* newNode= new ListNode();
            newNode->val= n%10;
            if(head==NULL){
                head= newNode;
                tail= newNode;
            }
            else{
                tail->next= newNode;
                tail= newNode;
            }
            temp1= temp1->next;
        }
        while(temp2 != NULL){
            int n= temp2->val+carry;
            carry= n/10;
            ListNode* newNode= new ListNode();
            newNode->val= n%10;
            if(head==NULL){
                head= newNode;
                tail= newNode;
            }
            else{
                tail->next= newNode;
                tail= newNode;
            }
            temp2= temp2->next;
        }
        if(carry != 0){
            ListNode* newNode= new ListNode();
            newNode->val= carry;
            tail->next= newNode;
            tail= newNode;
        }
        return head;
    }
};