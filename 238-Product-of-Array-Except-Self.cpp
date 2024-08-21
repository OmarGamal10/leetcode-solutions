class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //prefix product O(n)..and suffix
        //This made me struggle a bit because I didnt know immediately how to deal with a zero in the array
        vector<int>prefProd;
        vector<int>suffProd;
        vector<int>ans;
        int size=nums.size();
        int totalPre=1;
        int totalSuff=1;
        for(int i=0;i<size;i++){
            totalPre*=nums[i];
            totalSuff*=nums[size-i-1];
            prefProd.push_back(totalPre);
            suffProd.push_back(totalSuff);
        }
        reverse(suffProd.begin(),suffProd.end());
        for(int i=0;i<size;i++)
        {   
            if(i==0){
                ans.push_back(suffProd[1]);
                continue;
            }
            if(i==size-1){
                ans.push_back(prefProd[i-1]);
                continue;
            }
            else
                ans.push_back(prefProd[i-1]*suffProd[i+1]);
        }
        return ans;
    }
};