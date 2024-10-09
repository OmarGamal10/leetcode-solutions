class Solution {
public:
    void permute(vector<vector<int>>&ans,vector<int>&nums,vector<int>&curPerm,int size,int i,vector<bool>&isUsed){
        if(i==size){
            ans.push_back(curPerm);
            return;
        }
        for(int j=0;j<size;++j){
            if(isUsed[j])
                continue;
            curPerm.push_back(nums[j]);
            isUsed[j]=true;
            permute(ans,nums,curPerm,size,i+1,isUsed);
            curPerm.pop_back();
            isUsed[j]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int size=nums.size();
        vector<vector<int>>ans;
        vector<int>curPerm;
        vector<bool>isUsed(size,false);
        permute(ans,nums,curPerm,size,0,isUsed);
        return ans;
    }
};