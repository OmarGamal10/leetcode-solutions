/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>map;
        Node*p=head;
        while(p){
           map[p]=new Node(p->val);
           p=p->next;
        }
        p=head;
        while(p){
            map[p]->next=map[p->next];
            map[p]->random=map[p->random];
            p=p->next;
        }
        return map[head];
    }
};