class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //array with n+1 integers with a range from 1-n can be treated as an array of pointers..linked list.,where each value points to a position 
        //impossible to solve without seeing before
        int s=0,f=0;
        while(true){
            s=nums[s];
            f=nums[nums[f]];
            if(s==f)
                break;
        }
        int s2=0;
        while(true){
            s=nums[s];
            s2=nums[s2];
            if(s==s2)
                break;
        }
        return s;

    }
};