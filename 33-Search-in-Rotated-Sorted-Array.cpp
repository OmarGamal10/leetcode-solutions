class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size();
        int l=0,r=size-1,mid;
        int piv;
        //find pivot
        while(l<r){
            mid=(l+r)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }else{
                r=mid;
            }
        }
        piv=l; //where rotation occured
        l=0;
        r=size-1;
        while(l<=r){
            mid=(l+r)/2;
            int adjusted=(mid+piv)%size;
            if(nums[adjusted]>target){
                r=mid-1;
            }else if(nums[adjusted]<target){
                l=mid+1;
            }else{
                return adjusted;
            }
        }
        return -1;
    }
};