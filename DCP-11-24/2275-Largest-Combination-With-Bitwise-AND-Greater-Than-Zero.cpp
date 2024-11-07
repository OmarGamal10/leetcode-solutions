class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int arr[32]{0};
        int i=0;
        for(int n:candidates){
            i=0;
            while(n!=0){
                arr[i]+=1&n;
                n>>=1;
                i++;
            }
        }
        int res=INT_MIN;
        for(int i=0;i<32;++i)
            res=res>=arr[i]?res:arr[i];
        return res;
    }
};