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
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow= slow->next;
            fast= fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};

int main(){
    head1= insert(3, head1);
    head1= insert(0, head1);
    head1= insert(2, head1);
    head1= insert(-4, head1);
    head1->next->next->next->next= head1->next->next;
    Solution obj;
    cout<<obj.hasCycle(head1);
    return 0;
}