class Solution {
public:
    //good question
    void subsDup(vector<vector<int>>&ans,vector<int>&current,vector<int>&nums,int size,int i){
        if(i==size){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        subsDup(ans,current,nums,size,i+1);
        current.pop_back();
        while(i<size-1&&nums[i]==nums[i+1])
            i++;
        subsDup(ans,current,nums,size,i+1);
        }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>current;
        int n=nums.size();
        subsDup(ans,current,nums,n,0);
        return ans;
    }
};