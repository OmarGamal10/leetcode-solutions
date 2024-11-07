/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*>que;
        que.push(root);
        Node*temp=nullptr;
        while(!que.empty()){
            int i=que.size();
            for(;i>0;--i){
                temp=que.front();
                if(temp->left)
                    que.push(temp->left);
                if(temp->right)
                    que.push(temp->right);
                if(i==1){
                    temp->next=nullptr;
                    que.pop();
                    continue;
                }
                que.pop();
                temp->next=que.front();
            }
        }
        return root;
    }
};