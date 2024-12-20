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
        if(head==NULL || head->next==NULL){
            return NULL;
        }

        int l=1;
        ListNode* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            temp=temp->next;
            l++;
        }
        ListNode* tempp=head;
        if(l-n==0) return tempp->next;

        int run=l-n-1;
        temp=head;
        while(run>0){
            temp=temp->next;
            run--;
        }
        temp->next=temp->next->next;
        return head;

    }
};