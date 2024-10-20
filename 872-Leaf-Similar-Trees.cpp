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
    void getLeafSequence(TreeNode*root,vector<int>&seq){
        if(!root)
            return;
        if(!root->left&&!root->right){
            seq.push_back(root->val);
            return;
        }
        getLeafSequence(root->left,seq);
        getLeafSequence(root->right,seq);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>seq1;
        vector<int>seq2;
        getLeafSequence(root1,seq1);
        getLeafSequence(root2,seq2);
        if(seq1.size()!=seq2.size())
            return false;
        for(int i=0;i<seq1.size();++i){
            if(seq1[i]!=seq2[i])
                return false;
        }
        return true;

    }
};