class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int l=0;
        vector<int>res;
        bool flag;
        for(int r=0;r<=nums.size()-k;++r){
            flag=true;
            for(int i=r;i<r+k-1;++i){
                if(nums[i+1]-nums[i]!=1)
                {
                    flag=false;
                    break;
                }
            }
            res.push_back(flag?nums[r+k-1]:-1);
        }
        return res;
    }
};