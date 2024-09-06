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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p=list1,*q=list2;
        ListNode*holder=nullptr;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        while(p&&q){
            if(p->val<=q->val){
                holder=p;
                while(p&&p->val<=q->val){
                    holder=p;
                    p=p->next;
                }
                holder->next=q;
            }else{
                holder=q;
                while(q&&q->val<p->val){
                    holder=q;
                    q=q->next;
                }
                holder->next=p;
            }
        }
        return list1->val<=list2->val?list1:list2;
    }
};
