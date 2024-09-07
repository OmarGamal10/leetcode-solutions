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
//very good problem(annoying)...many edge cases
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*p=l1,*q=l2,*head=new ListNode(-1),*tail=head;
        vector<int>nums;
        int sum=0,carry=0;
        while(p||q||carry){
            int v1=p?p->val:0;
            int v2=q?q->val:0;
            sum=v1+v2+carry;
            carry=sum/10;
            sum%=10;
            tail->next=new ListNode(sum);
            tail=tail->next;
            p=p?p->next:nullptr;
            q=q?q->next:nullptr;
        }
        return head->next;
    }
};