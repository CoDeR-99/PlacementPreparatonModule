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
    int length(ListNode* head){
        int count= 0;
        ListNode* temp= head;
        while(temp){
            count++;
            temp= temp->next;
        }
        return count;
    }
    
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* nxt= NULL;
        while(curr){
            nxt= curr->next;
            curr->next= prev;
            prev= curr;
            curr= nxt;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return true;
        }
        int len= length(head);
        int mid= (len+1)/2;
        ListNode* middle= head;
        while(mid>1){
            middle= middle->next;
            mid--;
        }
        middle->next= reverse(middle->next);
        ListNode* temp1= head;
        ListNode* temp2= middle->next;
        if(len%2==0){
            while(temp1 != middle->next){
                if(temp1->val != temp2->val){
                    return false;
                }
                temp1= temp1->next;
                temp2= temp2->next;
            }
            return true;
        }
        else{
            while(temp1 != middle){
                if(temp1->val != temp2->val){
                    return false;
                }
                temp1= temp1->next;
                temp2= temp2->next;
            }
            return true;
        }
    }
};

int main(){
    head1= insert(1, head1);
    head1= insert(2, head1);
    head1= insert(3, head1);
    head1= insert(2, head1);
    head1= insert(1, head1);
    cout<<"Linked List: ";
    display(head1);
    Solution obj;
    if(obj.isPalindrome(head1)){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a Palindrome";
    }
    return 0;
}