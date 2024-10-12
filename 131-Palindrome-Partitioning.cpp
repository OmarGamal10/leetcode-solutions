class Solution {
public:
    bool checkPalindrome(string&s){
        if(s.empty())
            return false;
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
            return true;
    }

    void partition(vector<vector<string>>&ans,vector<string>current,string&s,int curChar){
        if(curChar==s.size()){
            ans.push_back(current);
            return;
        }
        for(int j=curChar;j<s.size();++j){
            string sub=s.substr(curChar,j-curChar+1);
            if(checkPalindrome(sub)){
                current.push_back(sub);
                partition(ans,current,s,j+1);
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>current;
        partition(ans,current,s,0);
        return ans;
    }
};