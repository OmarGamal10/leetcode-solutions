class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZ=0,countOne=0;
        int l=0;
        int ans=0;
        for(int r=0;r<nums.size();++r){
            nums[r]==1?countOne++:countZ++;
            if((r-l+1)-countOne>k){
                nums[l]==1?countOne--:countZ--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};