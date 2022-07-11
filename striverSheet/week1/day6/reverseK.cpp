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
    int lengthOfList(ListNode* head){
        ListNode* temp= head;
        int count= 0;
        while(temp){
            count++;
            temp= temp->next;
        }
        return count;
    }
    
    ListNode* helper(ListNode* head, int k, int len){
        if(len<k){
            return head;
        }
        ListNode *curr= head;
        ListNode *prev= NULL;
        ListNode *nxt= NULL;
        int count= 0;
        while(curr!=NULL && count<k){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
            count++;
        }
        if(curr != NULL){
            head->next= helper(curr, k, len-k);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length= lengthOfList(head);
        return helper(head, k, length);
    }
};

int main(){
    head1= insert(1, head1);
    head1= insert(2, head1);
    head1= insert(3, head1);
    head1= insert(4, head1);
    head1= insert(5, head1);
    cout<<"Original Linked List: ";
    display(head1);
    Solution obj;
    ListNode* Head= obj.reverseKGroup(head1, 3);
    cout<<"Linked list After reversing K nodes: ";
    display(Head);
    return 0;
}