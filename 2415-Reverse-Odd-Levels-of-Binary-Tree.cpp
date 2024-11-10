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
    void revert(vector<TreeNode*>&vec){
        int l=0,r=vec.size()-1;
        while(l<r){
            swap(vec[l]->val,vec[r]->val);
            l++;
            r--;
        }
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        int k=0;
        queue<TreeNode*>que;
        que.push(root);
        vector<TreeNode*>levelVec;
        while(!que.empty()){
            int size=que.size();
            levelVec.clear();
            for(int i=0;i<size;++i){
                TreeNode*top=que.front();
                if(top->left)
                    que.push(top->left);
                if(top->right)
                    que.push(top->right);
                if(k%2!=0)
                    levelVec.push_back(top);
                que.pop();
            }
            if(k%2!=0)
                revert(levelVec);
            k++;
        }
        return root;
    }
};