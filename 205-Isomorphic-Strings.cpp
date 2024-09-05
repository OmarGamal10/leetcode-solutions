class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>map;
        unordered_set<char>set;
        for(int i=0;i<s.size();i++){
            if(map.count(s[i])){
                if(map[s[i]]==t[i])
                    continue;
                else
                    return false;
            }
            map[s[i]]=t[i];
        }
        for(auto it=map.begin();it!=map.end();++it){
            set.insert(it->second);
        }
        if(set.size()!=map.size())
            return false;
        return true;
    }
};