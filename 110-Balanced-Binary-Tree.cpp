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
    int check(TreeNode*root,bool& ans){
        if(!root)
            return 0;
        int l=check(root->left,ans);
        int r=check(root->right,ans);
        if(abs(l-r)>1)
            ans=false;
        return max(l,r)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        int h=check(root,ans);
        return ans;
    }
};