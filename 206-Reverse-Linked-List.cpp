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
    void reverseRecursive(ListNode*p,ListNode*&head){
        if(!p)
            return;
        if(!p->next)
        {
            head=p;
            return;
        }
        reverseRecursive(p->next,head);
        p->next->next=p;
        p->next=nullptr;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode*p=head;
        reverseRecursive(p,head);
        return head;
    }
};