class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>res;
        int n=nums.size();
        for(int n:nums){
            freq[n]++;
        }
        for(auto kv:freq){
            if(kv.second>n/3)
                res.push_back(kv.first);
        }
        return res;
    }
};