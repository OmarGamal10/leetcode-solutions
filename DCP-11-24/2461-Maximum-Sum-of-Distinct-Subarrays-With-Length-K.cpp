class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;
        long long aux = 0;
        unordered_set<int> window;
        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            while (window.count(nums[r]) > 0) {
                window.erase(nums[l]);
                aux -= nums[l];
                l++;
            }
            window.insert(nums[r]);
            aux += nums[r];
            if (r - l + 1 > k) {
                window.erase(nums[l]);
                aux -= nums[l];
                l++;
            }
            
            if (r - l + 1 == k && window.size() == k) {
                ans = max(ans, aux);
            }
        }
        return ans;
    }
};