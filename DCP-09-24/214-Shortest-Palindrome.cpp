class Solution {
public:
    string shortestPalindrome(string s) {
        //rabin karp.. rolling hash
        if(s.empty())
            return \\;
        long long prefix=0;
        long long suffix=0;
        int base=27;
        int last=0;
        long long pow=1;
        int size=s.size();
        int mod= 1<<31;
        for(int i=0;i<size;++i){
            int hash=s[i] - 'a' + 1;
            prefix= (prefix*base+hash) %mod;           //shift left ...forward...abc/123
            suffix=(suffix+hash*pow) %mod;             //shift right ... backward... abc/321
            pow=(pow*base)%mod;
            if(prefix==suffix)
                last=i;
        }
        string sub=s.substr(last+1);
        reverse(sub.begin(),sub.end());
        return sub+s;
    }   
};