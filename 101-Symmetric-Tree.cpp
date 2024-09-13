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
    bool helper(TreeNode*rootLeftTree,TreeNode*rootRightTree){
        if(!rootLeftTree||!rootRightTree){
            if(!rootLeftTree&&!rootRightTree)
                return true;
            return false;
        }
        if(rootLeftTree->val!=rootRightTree->val)
            return false;
        
        return helper(rootLeftTree->left,rootRightTree->right)&&helper(rootLeftTree->right,         rootRightTree->left);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root->left,root->right);
    }
};