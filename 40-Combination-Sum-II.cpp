class Solution {
public:
    //good question 

    void generateCombs(vector<vector<int>>&ans,vector<int>&curComb,vector<int>&candidates,int target,int&sum,int i){
        if(sum==target){
            ans.push_back(curComb);
            return;
        }
        if(i==candidates.size()||sum>target)
            return;

        sum+=candidates[i];
        curComb.push_back(candidates[i]);
        generateCombs(ans,curComb,candidates,target,sum,i+1);
        sum-=candidates[i];
        curComb.pop_back();
        while(i<candidates.size()-1&&candidates[i]==candidates[i+1])
            i++;
        generateCombs(ans,curComb,candidates,target,sum,i+1);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curComb;
        int sum=0;
        generateCombs(ans,curComb,candidates,target,sum,0);
        return ans;
    }
};