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
    void dfs(TreeNode*root,int target,vector<vector<int>>&ans,vector<int>path){
        if(!root)
            return;
        path.push_back(root->val);
        if(!root->left&&!root->right&&target-root->val==0)
            ans.push_back(path);
        dfs(root->left,target-root->val,ans,path);
        dfs(root->right,target-root->val,ans,path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>ans;
        dfs(root,targetSum,ans,path);
        return ans;
    }
};