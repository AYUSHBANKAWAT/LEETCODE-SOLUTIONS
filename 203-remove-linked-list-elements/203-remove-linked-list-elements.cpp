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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * q = head;
        ListNode * p = new ListNode();
        ListNode * newhead = p;
        p->next = q;
        while( q!=nullptr){
            if( q->val == val ){
                p->next=q->next;
                q=q->next;
            }else{
                p=q;
                q=q->next;
            }
                       
        }
         return newhead->next;

    }
};