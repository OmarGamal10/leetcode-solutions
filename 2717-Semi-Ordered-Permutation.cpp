class Solution {
public:
    int findIndex(vector<int>&nums,int target){
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(nums[i]==target)
            return i;
        }
        return 0;
    }
    int semiOrderedPermutation(vector<int>& nums) {
        int size=nums.size()-1;
        int idxOne=findIndex(nums,1);
        int idxMax=findIndex(nums,size+1);
        int ans=idxOne+(size-idxMax);
        if(idxOne>idxMax){
            ans--;   
        }
        return ans;
    }
};