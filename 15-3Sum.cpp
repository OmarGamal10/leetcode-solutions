class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int size=nums.size();
        if(size<3){
            
            return ans;
        }
        sort(nums.begin(),nums.end());
        int left,right;
        int target;
        bool c=false;
        
        for(int i=0;i<size;++i){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            target=0-nums[i];
            left=i+1;
            right=size-1;
            while(left<right){
                if(nums[left]+nums[right]>target){
                    right--;
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }
                else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    while(left<right&&nums[left]==nums[left-1])
                        left++;
                }
            }
        }
        return ans;
    }
};