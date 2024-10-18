class Solution {
public:
    //not very easy tbh
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0;
        if(n==0)
            return true;
        for(int i=0;i<flowerbed.size();++i){
            if(flowerbed[i]==0){
                bool left=i==0||flowerbed[i-1]==0;   //shortcircuiting handles edgecases
                bool right=i==flowerbed.size()-1||flowerbed[i+1]==0;
                if(left&&right){
                    cnt++;
                    flowerbed[i]=1;
                }
                if(cnt==n)
                    return true;
            }
        }

        return false;
    }
};