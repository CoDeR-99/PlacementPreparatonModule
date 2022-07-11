#include<bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
 };
 ListNode* head1= NULL;

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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return head;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        bool flag= false;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                flag= true;
                break;
            }
        }
        if(flag){
            fast= head;
            while(fast != slow){
                fast= fast->next;
                slow= slow->next;
            }
            return slow;
        }
        else
            return NULL;
    }
};

int main(){
    head1= insert(3, head1);
    head1= insert(0, head1);
    head1= insert(2, head1);
    head1= insert(-4, head1);
    head1->next->next->next->next= head1->next->next;
    Solution obj;
    cout<<obj.detectCycle(head1)->val;
    return 0;
}