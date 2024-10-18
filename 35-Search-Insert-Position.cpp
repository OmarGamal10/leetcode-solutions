class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        int mid;
        while(l<=r){
            mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l=mid+1;
            else if(nums[mid]>target)
                r=mid-1;
        }
        return l;
    }
};