class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sums;
        int size =nums.size();
        long long cur=0;
        for(int i=0;i<size;i++){
            cur=0;
            for(int j=i;j<size;j++){
                cur+=nums[j];
                sums.push_back(cur);
            }
        }
        cur=0;
        sort(sums.begin(),sums.end());
        for(int i=left-1;i<right;i++){
            cur+=sums[i];
        }
        return cur%1000000007;

    }
};