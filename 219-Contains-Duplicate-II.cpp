class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0)
        return false;
        int size=nums.size();
        unordered_set<int>set;
        int left=0;
        for(int i=0;i<size;++i){
            if(i-left>k){
                set.erase(nums[left]);
                left++;
            }
            if(set.count(nums[i]))
                return true;
            set.insert(nums[i]);
        }
        return false;
    }
};