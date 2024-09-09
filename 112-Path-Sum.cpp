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
    bool helper(TreeNode*root,int targetSum){
        if(!root)
            return false;
        if(!root->left&&!root->right){
            if(targetSum-root->val==0)
                return true;
            return false;
        }
        bool x=helper(root->left,targetSum-root->val);
        bool y=helper(root->right,targetSum-root->val);
        return x||y;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return helper(root,targetSum);
    }
};