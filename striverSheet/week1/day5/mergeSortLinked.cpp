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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        if(list1->val > list2->val) swap(list1, list2);
        ListNode* head= list1;
        while(list1 != NULL && list2 != NULL){
            ListNode* temp= NULL;
            while(list1 != NULL && list1->val <= list2->val){
                temp= list1;
                list1= list1->next;
            }
            temp->next= list2;
            swap(list1, list2);
        }
        return head;
    }
};

int main(){
    head1= insert(1, head1);
    head1= insert(2, head1);
    head1= insert(4, head1);
    head2= insert(1, head2);
    head2= insert(3, head2);
    head2= insert(4, head2);
    cout<<"First Linked List: ";
    display(head1);
    cout<<"Second Linked List: ";
    display(head2);
    Solution obj;
    ListNode* Head= obj.mergeTwoLists(head1, head2);
    cout<<"Merged Linked List: ";
    display(Head);
    return 0;
}