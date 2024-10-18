class Solution {
public:
    void split (vector<string>&words,string&s,string currWord){
        for(int i = 0;i < s.size(); ++i){
            if(isspace(s[i])){
                if(currWord.empty())
                    continue;
                words.push_back(currWord);
                currWord.clear();
            }
            else{
                currWord+=s[i];
            }
        }
        if(!currWord.empty())
            words.push_back(currWord);
    }
    string reverseWords(string s) {
        vector<string>words;
        split(words,s,\\);
        string ans;
        for(int i=words.size()-1;i>=0;--i){
            ans+=words[i];
            if(i!=0)
                ans+=\ \;
        }
        return ans;
    }
};