class Solution {
public:
//very satisfying coming up with average o(n) solution
//1-hashSet
//2-check subsequence for every number in the set and update answer accordingly
//3-trick for o(n) is condition that we only check if the number is the first of a sequence
//impossible for every element in a SET to be the \absolute\ start of a sequence 
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
    for (auto it=hashSet.begin(); it!=hashSet.end(); it++) {
        ans = 1;
        if(hashSet.count((*it)-1)==0){ //the starts of a sequence
        for (int i = 1; i < nums.size(); i++) {
            if (hashSet.count((*it) + i)) {
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