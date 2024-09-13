class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        int r=size-1;
        bool flag=true;
        for(int l=size-2;l>=0;--l){
            if(nums[l]>=r-l) //can reach
            { 
                r=l;
                flag=true;
            }
            else
                flag=false;
        }
        return flag;

    }
};