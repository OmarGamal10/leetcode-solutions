class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    if (s.size() == 0)
        return 0;
    unordered_set<char>dup;
    int L = 0;
    int size = s.size();
    int curLength = 0;
    int length = 0;
    for (int R = 0; R < size; R++) {
        if (dup.count(s[R]) == 0) {
            curLength++;
            dup.insert(s[R]);
        }
        else {
            while (dup.count(s[R])) {
                dup.erase(s[L]);
                L++;
                curLength--;
            }
            dup.insert(s[R]);
            curLength++;
        }
        length = max(length, curLength);
    }
    return length;
}
};