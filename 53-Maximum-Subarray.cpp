class Solution {
public:
    int maxSubArray(vector<int> nums) {
    int n = nums.size();
    int curSum = 0, res = INT_MIN;
    int L = 0;
    for (int i = 0; i < n; i++) {
        curSum += nums[i];
        if (i > 0 && (nums[i]>curSum)) {
            while (curSum < nums[i]) {
                curSum -= nums[L];
                L++;
            }
        }
        res = max(res, curSum);
    }
    return res;
}
};