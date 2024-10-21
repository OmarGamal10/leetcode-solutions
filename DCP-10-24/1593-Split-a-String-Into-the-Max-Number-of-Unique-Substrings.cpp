class Solution {
public:
    void split(string&s,unordered_set<string>&curr,int i,int &ans){
        if(i==s.size())
        {
            ans=max((int)curr.size(),ans);
            return;
        }
        if(curr.size()+(s.size()-i)<=ans)
            return;
        for(int j=i;j<=s.size();++j){
            string sub=s.substr(i,j-i+1);
            if(curr.count(sub))
                continue;
            else{
                curr.insert(sub);
                split(s,curr,j+1,ans);
                curr.erase(sub);
                
            }
        }
    }

    int maxUniqueSplit(string s) {
        unordered_set<string>curr;
        int ans=0;
        split(s,curr,0,ans);
        return ans;
    }
};