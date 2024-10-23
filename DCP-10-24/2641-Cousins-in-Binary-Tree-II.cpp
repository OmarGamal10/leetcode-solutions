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
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int, pair<int, int>> map; // to store values of two siblings
        queue<TreeNode*> que;
        vector<TreeNode*> vec;
        que.push(root);
        root->val = 0;  // root has no cousins, so set to 0

        while (!que.empty()) {
            int levelSize = que.size();
            int sumLevel = 0;

            // First pass: calculate the sum of the current level and sibling values
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = que.front();
                que.pop();
                map[i] = make_pair(0, 0); // initialize siblings' values

                if (node->left) {
                    que.push(node->left);
                    map[i].first = node->left->val; 
                    sumLevel += node->left->val;
                }
                if (node->right) {
                    que.push(node->right);
                    map[i].second = node->right->val;
                    sumLevel += node->right->val;
                }
                vec.push_back(node); 
            }

            
            for (int i = 0; i < vec.size(); ++i) {
                TreeNode* node = vec[i];
                if (node->left) {
                    node->left->val = sumLevel - map[i].first - map[i].second;
                }
                if (node->right) {
                    node->right->val = sumLevel - map[i].first - map[i].second;
                }
            }
            vec.clear();
            map.clear();
        }

        return root;
    }
};
