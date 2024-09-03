class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int largePlaceHolder=n+m-1;
        int i=m-1;
        int j=n-1;
        while(j>=0&&i>=0){
            if(nums2[j]>nums1[i]){
                nums1[largePlaceHolder]=nums2[j];
                j--;
            }else{
                nums1[largePlaceHolder]=nums1[i];
                i--;
            }
                largePlaceHolder--;
        }
        //if smaller elements in num2, they werent copied to nums1
        while(j>=0){
            nums1[largePlaceHolder]=nums2[j];
            largePlaceHolder--;
            j--;
        }
        return;
    }
};