/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*>que;
        unordered_map<int,pair<int,int>>map;
        if(!root)
            return false;
        que.push(root);
        int depth=1;
        while(!que.empty()){
            int levelSize=que.size();
            for(int i=0;i<levelSize;++i){
                if(que.front()->left){
                    que.push(que.front()->left);
                    map[que.front()->left->val]=make_pair(depth,i);
                }
                if(que.front()->right){
                    que.push(que.front()->right);
                    map[que.front()->right->val]=make_pair(depth,i);
                }
                que.pop();
            }
            depth++;
        }
        return map[x].first==map[y].first&&map[x].second!=map[y].second;

        
    }
};