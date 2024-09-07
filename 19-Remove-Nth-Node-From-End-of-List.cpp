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
    ListNode* helper(ListNode*p,int&c,int n){
        if(!p){
            c=0;
            return p;
        }
        p->next=helper(p->next,c,n);
        c++;
        if(c==n)
            return p->next;
        return p;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        head=helper(head,c,n);
        return head;
    }
};