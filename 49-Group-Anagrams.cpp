class Solution {
public:
    //O(n*LlogL)L is avg string size
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_set<string>done;
        vector<string>angs;
        vector<string>original(strs);
        for(auto&s:strs){
            sort(s.begin(),s.end());
        }
        for(int i=0;i<strs.size();i++){
            angs.clear();
            if(done.count(strs[i]))
            continue;
            angs.push_back(original[i]);
            for(int j=i+1;j<strs.size();j++){
                if(strs[i]==strs[j]){
                    angs.push_back(original[j]);
                    done.insert(strs[j]);
                    }
            }
            ans.push_back(angs);
        }
        return ans;
    }
};