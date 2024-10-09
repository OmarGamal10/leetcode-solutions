class Solution {
public:
   void generateCombs(vector<vector<int>>&ans,vector<int>&curComb,vector<int>&candidates,int target,int size,int i,int&sum){
        if(sum==target){
            ans.push_back(curComb);
            return;
        }
        if(sum>target)
            return;
        for(int j=i;j<size;++j){
            curComb.push_back(candidates[j]);
            sum+=candidates[j];
            generateCombs(ans,curComb,candidates,target,size,j,sum);
            curComb.pop_back();
            sum-=candidates[j];
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>curComb;
        int sum=0;
        generateCombs(ans,curComb,candidates,target,n,0,sum);
        return ans;
    }
};