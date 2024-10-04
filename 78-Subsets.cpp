class Solution {
public:
    void helper(int size,int i,vector<int>&nums,vector<int>&cur,vector<vector<int>>&subsets){
        if(i==size){
            subsets.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);
        helper(size,i+1,nums,cur,subsets);
        cur.pop_back();
        helper(size,i+1,nums,cur,subsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>cur;
        vector<vector<int>>subsets;
        helper(nums.size(),0,nums,cur,subsets);
        return subsets;
    }
};