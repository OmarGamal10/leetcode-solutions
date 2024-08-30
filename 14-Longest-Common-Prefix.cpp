class Solution {
public:
    string getShortest(vector<string>&strs){
        int size;
        int minSize=INT_MAX;
        string minSt;
        for(int c=0;c<strs.size();c++){
            size=strs[c].size();
            if(minSize>size){
                minSize=size;
                minSt=strs[c];
            }
        }
        return minSt;

    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return \\;
        }
        string pref=getShortest(strs);
        int prefSize=pref.size();
        for(const string&str:strs){
            for(int i=0;i<prefSize;i++){
                if(pref[i]!=str[i]){
                    pref=pref.substr(0,i);
                    break;
                }
            }
        }
    return pref;
    }
};