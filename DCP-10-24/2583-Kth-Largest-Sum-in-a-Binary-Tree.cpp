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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long>sums;
        queue<TreeNode*>levels;
        long long sum=0;
        levels.push(root);
        while(!levels.empty()){
            int levelSize=levels.size();
            sum=0;
            for(int i=0;i<levelSize;++i){
                sum+=(long long)levels.front()->val;
            if(levels.front()->left)
                levels.push(levels.front()->left);
            if(levels.front()->right)
                levels.push(levels.front()->right);
            levels.pop();
            }
            sums.push_back(sum);
        }
        sort(sums.begin(),sums.end(),[](const auto&a,const auto&b){
            return a>b;
        });
        return k>sums.size()?-1:sums[k-1];
        
    }
};