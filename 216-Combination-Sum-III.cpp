class Solution {
public:

    void generate(vector<vector<int>>&ans,vector<int>&curComb,int i,int k,int n,int sum){
        if(curComb.size()>k)
            return;
        if(sum==n&&curComb.size()==k){
            ans.push_back(curComb);
            return;
        }
        if(i>9||sum>n)
            return;
        
        curComb.push_back(i);
        generate(ans,curComb,i+1,k,n,sum+i);
        curComb.pop_back();
        generate(ans,curComb,i+1,k,n,sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curComb;
        generate(ans,curComb,1,k,n,0);

        return ans;
    }
};