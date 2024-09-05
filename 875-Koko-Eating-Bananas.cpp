class Solution {
public:
    long long checkHours(vector<int>&piles,int k){
        long long ans=0;
        for(int i=0;i<piles.size();i++){
             ans += ceil(double(piles[i]) / k);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*(max_element(piles.begin(),piles.end()));
        int mini=1;
        int ans=INT_MAX;
        int left=mini,right=maxi,mid;
        while(left<=right){
            mid=(left+right)/2;
            if(checkHours(piles,mid)<=h){
                right=mid-1;
                ans=min(ans,mid);
            }
            else{
                left=mid+1;
            }
        }
        return ans;  
    }
};