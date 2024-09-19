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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>que;
        vector<int>level;
        vector<vector<int>>ans;
        if(!root)
            return {};
        que.push(root);
        while(que.size()){
            int levelSize=que.size();
            level.clear();
            for(int i=0;i<levelSize;i++){
                level.push_back(que.front()->val);
                if(que.front()->left)
                    que.push(que.front()->left);
                if(que.front()->right)
                    que.push(que.front()->right);
                que.pop();
            }
            ans.push_back(level);
        }
        return ans;

    }
};