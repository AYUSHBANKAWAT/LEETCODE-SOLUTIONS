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
        queue<int>s;
        ListNode* p = head;
        while(p!=nullptr){
            if( p->val!=val)
            s.push(p->val);
            p=p->next;
        }
        p = head;
        ListNode* temp;
        if( s.empty() )return nullptr;
        while( !s.empty() ){
            temp = p;
            p->val = s.front();
            s.pop();
            p=p->next;
        }
        if( temp != nullptr )
        temp->next=nullptr;
        //p= nullptr;
        
        return head;
    }
};