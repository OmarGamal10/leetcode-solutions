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
    //good question
    void reorderList(ListNode* head) {
        ListNode*s=head,*f=head->next;
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        ListNode*second=s->next;
        s->next=nullptr; //new list end
        //reverse the second list
        ListNode*prev=nullptr;
        while(second){
            ListNode*temp=second->next;
            second->next=prev;
            prev=second;
            second=temp;
        }
        ListNode*p=head;
        second=prev; //new head of the reversed half
        while(second){
            ListNode*temp1=p->next;
            ListNode*temp2=second->next;
            p->next=second;
            second->next=temp1;
            p=temp1;
            second=temp2;
        }
    }
};