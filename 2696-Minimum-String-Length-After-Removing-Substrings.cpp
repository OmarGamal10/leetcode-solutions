class Solution {
public:
    int minLength(string s) {
        stack<char>charStack;
        int ans=s.size();
        for(int i=0;i<s.size();++i){
            if((!charStack.empty())&&((s[i]=='B'&&charStack.top()=='A') || (s[i]=='D'&&charStack.top()=='C')))
            {
                ans-=2;
                charStack.pop();
            }
            else
                charStack.push(s[i]);
        }
        return ans;
    }
};