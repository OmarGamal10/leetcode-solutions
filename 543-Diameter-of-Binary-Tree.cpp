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
    int helper(TreeNode*root,int& diameter){
        if(!root)
            return 0;
        int l=helper(root->left,diameter);
        int r=helper(root->right,diameter);
        diameter=max(l+r+1,diameter);
        return l>=r?l+1:r+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        helper(root,diameter);
        return diameter-1;
    }
};