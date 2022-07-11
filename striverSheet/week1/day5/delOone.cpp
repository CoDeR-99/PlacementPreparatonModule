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
    void deleteNode(ListNode* node) {
        node->val= node->next->val;
        node->next= node->next->next;
        return;
    }
};

int main(){
    insert(4);
    insert(5);
    insert(1);
    insert(9);
    ListNode* temp= head->next;
    Solution obj;
    obj.deleteNode(temp);
    display(head);
    return 0;
}