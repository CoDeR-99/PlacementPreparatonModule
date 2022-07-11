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

void display() {
   ListNode* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->val <<" ";
      ptr = ptr->next;
   }
   cout<<"\n";
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* curr= reverseList(head->next);
        head->next->next= head;
        head->next= NULL;
        return curr;
    }
};

int main(){
    insert(3);
    insert(1);
    insert(7);
    insert(2);
    insert(9);
    cout<<"The linked list is: ";
    display();
    cout<<"The reverse linked list: ";
    Solution obj;
    head= obj.reverseList(head);
    display();
    return 0;
}