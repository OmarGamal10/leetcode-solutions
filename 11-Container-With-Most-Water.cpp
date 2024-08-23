class Solution {
public:
    int maxArea(vector<int>& height) {
        int size=height.size()-1;
        int left=0,right=size;
        int ans=0;
        int temp;
        int i=0;
        while(left<right){
            temp=min(height[left],height[right])*(size-i);
            ans=max(ans,temp);
            if(height[left]==height[right]){
                if(height[left+1]>height[right-1])
                    left++;
                    else
                    right--;
            }
            else{
                height[left]>height[right]?right--:left++;
            }
            i++;
        }
        return ans;
    }
};