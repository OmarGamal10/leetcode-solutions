class Solution {
public:
    int maxCount(unordered_map<char,int>&map){
        if(map.empty())
            return 0;
        int maxi=0;
        for(auto it = map.begin(); it != map.end(); ++it){
            maxi=max(maxi,it->second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int L=0,ans=0;
        unordered_map<char,int>freqMap;
        int size=s.size();
        for(int R=0;R<size;++R){
            freqMap[s[R]]++;
            //check if Invalid window
            if((R-L+1)-maxCount(freqMap)>k){
                    freqMap[s[L]]--;
                    L++;
            }
            if(R-L+1>ans){
                ans=R-L+1;
            }
        }
        return ans;
    }
};