class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int curSum=0;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curSum+=nums[i];
            while(curSum>=target){
                ans=min(ans,i-left+1);
                curSum-=nums[left];
                left++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};