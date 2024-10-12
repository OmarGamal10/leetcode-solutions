class Solution {
public:
    //very good question
    void permute(vector<vector<int>>&ans,vector<int>&current,vector<bool>&isUsed,vector<int>&nums,int i)
    {
        if(i==nums.size()){
            ans.push_back(current);
            return;
        }

        for(int j=0;j<nums.size();++j){
            //the one before me is equal to me and not used now (so it was used before at this position)
            if(isUsed[j]||(j>0&&nums[j]==nums[j-1]&&!isUsed[j-1]))
                continue;
            current.push_back(nums[j]);
            isUsed[j]=true;
            permute(ans,current,isUsed,nums,i+1);
            current.pop_back();
            isUsed[j]=false;
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>current;
        vector<vector<int>>ans;
        vector<bool>isUsed(nums.size(),false);
        permute(ans,current,isUsed,nums,0);
        return ans;
    }
};