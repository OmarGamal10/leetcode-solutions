class Solution {
public:

    void generate(vector<string>&ans,string&digits,unordered_map<char,string>&map,string currString,int curDigit){
        if(currString.size()==digits.size()){
            ans.push_back(currString);
        }
        if(curDigit==digits.size()){
            return;
        }

        for(int i=0;i<map[digits[curDigit]].size();++i){
            generate(ans,digits,map,currString+map[digits[curDigit]][i],curDigit+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {};
        unordered_map<char,string>map;
        map['2']=\abc\;
        map['3']=\def\;
        map['4']=\ghi\;
        map['5']=\jkl\;
        map['6']=\mno\;
        map['7']=\pqrs\;
        map['8']=\tuv\;
        map['9']=\wxyz\;
        vector<string>ans;

        generate(ans,digits,map,\\,0);
        return ans;
    }
};