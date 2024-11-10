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
    TreeNode*builder(vector<int>&preorder,vector<int>&inorder,int lpre,int rpre,int lin,int rin,unordered_map<int,int>&in){
        if(rpre<lpre||rin<lin)
            return nullptr;
        TreeNode*root=new TreeNode(preorder[lpre]);
        int mid=in[preorder[lpre]];
        int leftSize=mid-lin;
        root->left=builder(preorder,inorder,lpre+1,lpre+leftSize,lin,mid-1,in);
        root->right=builder(preorder,inorder,lpre+leftSize+1,rpre,mid+1,rin,in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>in;
        for(int i=0;i<inorder.size();++i){
            in[inorder[i]]=i;
        }
       return builder(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,in);
    }
};