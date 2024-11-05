class Solution {
public:
    int minChanges(string s) {
        int zeros=0,ones=0;
        int ans=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='0'){
                if(ones%2!=0){
                    ones++;
                    ans++;
                }
                else
                    zeros++;
                    ones=0;
            }
            else{
               if(zeros%2!=0){
                    zeros++;
                    ans++;
               }
               else{
                ones++;
                zeros=0;
               }
            }
        }
        return ans;
    }
};