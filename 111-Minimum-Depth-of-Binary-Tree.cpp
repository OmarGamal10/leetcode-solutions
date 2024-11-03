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
    void helper(TreeNode*root,int&mindepth,int depth){
        if(!root)
            return;
        if(!root->left&&!root->right){
            mindepth=min(mindepth,depth+1);
            return;
        }
        helper(root->left,mindepth,depth+1);
        helper(root->right,mindepth,depth+1);

    }
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        int mindepth=INT_MAX;
        helper(root,mindepth,0);
        return mindepth;
    }
};