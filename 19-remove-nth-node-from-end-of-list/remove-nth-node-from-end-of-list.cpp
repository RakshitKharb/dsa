/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        int size=1;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            size++;
        }
        temp=head;
        if(size-n==0) return temp->next;
        int mover=size-n;
        while(mover>1){
            temp=temp->next;
            mover--;
        }
        
        temp->next=temp->next->next;
        
        
        return head;
    }
};