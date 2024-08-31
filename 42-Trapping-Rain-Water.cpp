class Solution {
public:
    int getMaxRight(int ind,vector<int>& height,int size){
        int maxi=0;
        for(int i=ind;i<size;++i){
            maxi=max(maxi,height[i]);
        }
        return maxi;
    }
    int trap(vector<int>& height) {
        int size=height.size();
        unordered_map<char,int>map;
        int ans=0;
        int maxR;
        map['m']=height[0];
        for(int i=1;i<size;++i){
            if(map['m']<=height[i])
            {
                map['m']=height[i];
                 continue;
            }
            maxR=getMaxRight(i,height,size);
            if(maxR<=height[i]){
                continue;
            }
            ans+=min(maxR,map['m'])-height[i];
        }
        return ans;
    }
};