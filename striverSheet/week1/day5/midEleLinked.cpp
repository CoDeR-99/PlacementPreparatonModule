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
    ListNode* middleNode(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* temp= head;
        int count= 0;
        while(temp!=NULL){
            count++;
            temp= temp->next;
        }
        count= (count/2)+1;
        temp= head;
        while(1){
            if(count==1){
                break;
            }
            temp= temp->next;
            count--;
        }
        return temp;
    }
};

int main(){
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    insert(10);
    Solution obj;
    display(obj.middleNode(head));
    return 0;
}