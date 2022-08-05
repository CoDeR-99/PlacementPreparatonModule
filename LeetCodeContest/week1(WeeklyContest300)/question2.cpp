#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<vector<int>> spiralMatrix(int r, int c, ListNode* head) {
        vector<vector<int>> matrix(r, vector<int>(c, -1));
        int top=0, left=0, right= c-1, bottom= r-1;
        ListNode* temp= head;
        while(top<=bottom && left<=right && temp!=NULL){
            for(int i= left; i<=right; i++){
                matrix[top][i]= temp->val;
                temp= temp->next;
                if(temp==NULL){
                    break;
                }
            }
            if(temp==NULL){
                    break;
                }
            top++;
            for(int i= top; i<=bottom; i++){
                matrix[i][right]= temp->val;
                temp= temp->next;
                if(temp==NULL){
                    break;
                }
            }
            if(temp==NULL){
                    break;
                }
            right--;
            if(top<=bottom){
                for(int i= right; i>=left; i--){
                    matrix[bottom][i]= temp->val;
                    temp= temp->next;
                    if(temp==NULL){
                    break;
                }
                }
                if(temp==NULL){
                    break;
                }
                bottom--;
            }
            if(left<=right){
                for(int i= bottom; i>=top; i--){
                    matrix[i][left]= temp->val;
                    temp= temp->next;
                    if(temp==NULL){
                    break;
                }
                }
                if(temp==NULL){
                    break;
                }
                left++;
            }
        }
        return matrix;
    }
};