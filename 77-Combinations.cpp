class Solution {
public:

    void generateCombs(vector<vector<int>>&ans,vector<int>&curComb,int i,int n,int k){
        if(curComb.size()==k){
            ans.push_back(curComb);
            return;
        }
        if(i>n){
            return;
        }
        
        curComb.push_back(i);
        generateCombs(ans,curComb,i+1,n,k);
        curComb.pop_back();
        generateCombs(ans,curComb,i+1,n,k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>curComb;

        generateCombs(ans,curComb,1,n,k);
        return ans;
    }
};