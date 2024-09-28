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
    int ans(TreeNode*root,int&k){
        if(!root)
            return 0;
        int l=ans(root->left,k);
        k--;
        if(k==0)
            return root->val;
        int r=ans(root->right,k);
        return l+r;
    }
    int kthSmallest(TreeNode* root, int k) {
        return ans(root,k);
    }
};