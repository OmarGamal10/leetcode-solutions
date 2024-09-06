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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>set;
        for(int n:nums)
            set.insert(n);
        while(set.count(head->val))
            head=head->next;
        ListNode*p=head->next,*t=head;
        while(p){
            if(set.count(p->val)){
                t->next=p->next;
            }else{
                t=p;
            }
                p=p->next;
        }
        return head;
    }
};