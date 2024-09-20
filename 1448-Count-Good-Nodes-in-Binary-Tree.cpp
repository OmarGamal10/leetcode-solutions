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
    //took a while to get what it meant lol
    void helper(TreeNode*root,int val,int&ans){
        if(!root)
            return;
        if(root->val>=val){
            ans++;
            val=root->val;
        }
        helper(root->left,val,ans);
        helper(root->right,val,ans);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        int ans=0;
        helper(root,root->val,ans);
        return ans;
    }
};