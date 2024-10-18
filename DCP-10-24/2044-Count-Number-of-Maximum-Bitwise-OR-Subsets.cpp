class Solution {
public:
    void countRec(vector<int>&nums,vector<int>&cur,int&Or,int&ans,int i){
        if(i==nums.size()){
            int curOr=0;
            for(int n:cur){
                curOr|=n;
            }
            if(curOr==Or)
                ans++;
            return;
        }
        cur.push_back(nums[i]);
        countRec(nums,cur,Or,ans,i+1);
        cur.pop_back();
        countRec(nums,cur,Or,ans,i+1);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int Or=0;
        int ans=0;
        vector<int>curr;
        for(int n:nums)
            Or|=n;
        countRec(nums,curr,Or,ans,0);
        return ans;
    }
};