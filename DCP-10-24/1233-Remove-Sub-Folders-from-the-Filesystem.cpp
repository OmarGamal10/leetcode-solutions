class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string>ans;
        int i=0;
        while(i<folder.size()){
            if(folder[i]=="/" || folder[i].empty())
            {
                i++;
                continue;
            }
            string s = folder[i];
            ans.push_back(s);
            i++;
            while(i<folder.size()&&folder[i].find(s+'/')==0)
                i++;
        }
        return ans;
    }
};