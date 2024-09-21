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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return{};
        queue<TreeNode*>que;
        vector<int>ans;
        que.push(root);
        while(que.size()){
            int size=que.size();
            for(int i=0;i<size;++i){
                if(i==size-1)
                    ans.push_back(que.front()->val);
                if(que.front()->left)
                    que.push(que.front()->left);
                if(que.front()->right)
                    que.push(que.front()->right);
            que.pop();
            }
        }
        return ans;
    }
};