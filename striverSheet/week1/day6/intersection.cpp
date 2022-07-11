#include<bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
 };
ListNode* head1= NULL;
ListNode* head2= NULL;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int size1= 0, size2= 0;
        ListNode* temp1= headA;
        ListNode* temp2= headB;
        while(temp1){
            size1++;
            temp1= temp1->next;
        }
        while(temp2){
            size2++;
            temp2= temp2->next;
        }
        if(size2>size1){
            swap(size1, size2);
            swap(headA, headB);
        }
        temp1= headA;
        temp2= headB;
        int count= size1-size2;
        while(count--){
            temp1= temp1->next;
        }
        ListNode* ans= NULL;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1==temp2){
                ans= temp1;
                break;
            }
            temp1= temp1->next;
            temp2= temp2->next;
        }
        return ans;
    }
};

int main(){
    head1= insert(4, head1);
    head1= insert(1, head1);
    head1= insert(8, head1);
    head1= insert(4, head1);
    head1= insert(5, head1);
    head2= insert(5, head2);
    head2= insert(6, head2);
    head2= insert(1, head2);
    head2->next->next->next= head1->next->next;
    cout<<"First Linked List: ";
    display(head1);
    cout<<"Second Linked List: ";
    display(head2);
    Solution obj;
    ListNode* Head= obj.getIntersectionNode(head1, head2);
    cout<<"Intersection Point: "<<Head->val<<"\n";
    cout<<"Intersection Linked List: ";
    display(Head);
    return 0;
}