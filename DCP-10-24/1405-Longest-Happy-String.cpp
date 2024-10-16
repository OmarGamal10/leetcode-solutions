class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int currA=0;
        int currB=0;
        int currC=0;
        string ans;
        int maxSize=a+b+c;
        for(int i=0;i<maxSize;++i){
            if((a>=b&&a>=c&&currA!=2)||(a&&(currB==2||currC==2)&&currA!=2)){
                ans+='a';
                a--;
                currA++;
                currB=0;
                currC=0;
            }
            else if((b>=a&&b>=c&&currB!=2)||(b&&(currC==2||currA==2)&&currB!=2)){
                ans+='b';
                b--;
                currB++;
                currA=0;
                currC=0;
            }
            else if((c>=a&&c>=b&&currC!=2)||(c&&(currB==2||currA==2)&&currC!=2)){
                ans+='c';
                c--;
                currC++;
                currA=0;
                currB=0;
            }
        }
        return ans;
    }
};