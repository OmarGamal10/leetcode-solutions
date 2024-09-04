class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1,mid;
        if(left==right)
            return nums[0];
        while(left<=right)
        {
            mid=(left+right)/2;
            if(nums[right]<nums[mid]){
                left=mid+1;
            }
            else if(nums[left]>nums[mid]){
                right=mid;
            }
            else{
                return nums[left]; //im in normal order..ba3dy akbar w ably asghar,so ably
            }
        }
        return nums[0];
        
    }
};