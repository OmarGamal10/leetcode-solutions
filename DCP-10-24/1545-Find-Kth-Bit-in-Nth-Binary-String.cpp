class Solution {
public:
    
    char findKthBit(int n, int k) {
        string s="011";
        while(s.size()<=k){
            s+='1';
            string rev;
            for(int i=s.size()-2;i>=0;--i)
                rev+=s[i]=='0'?'1':'0';
            s+=rev;
        }
        return s[k-1];
    }
};