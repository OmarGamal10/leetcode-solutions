class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //in-place.. think quicksort partition
        //getting all non-vals to the left, will by def get all vals to the right
        int size=nums.size();
        int left=0;
        for(int i=0;i<size;++i){
            if(nums[left]==val&&nums[i]!=val){
                swap(nums[left],nums[i]);
            }
            if(nums[left]!=val)
                left++;

        }
        return left;
    }
};