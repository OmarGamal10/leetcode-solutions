class Solution {
public:
    int longestConsecutive(vector<int> nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int ans = 1;
    int longestAns = 1;
    unordered_set<int>hashSet;
    for (const auto& n : nums) {
        hashSet.insert(n);
    }
    for (int j = 0; j < nums.size(); j++) {
        ans = 1;
        if(hashSet.count(nums[j]-1)==0){ //the starts of a sequence
        for (int i = 1; i < nums.size(); i++) {
            if (hashSet.count(nums[j] + i)) {
                ans++;
            }
            else {
                longestAns = max(longestAns, ans);
                break;
            }
        }
    }
        longestAns = max(longestAns, ans);
    }

    return longestAns;
}
};