class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int firstOp;
        int secOp;
        for(string c:tokens){
            if(c==\+\||c==\-\||c==\*\||c==\/\){
                secOp=st.top();
                st.pop();
                firstOp=st.top();
                st.pop();
                if(c==\+\){
                    st.push(firstOp+secOp);
                }else if(c==\-\){
                    st.push(firstOp-secOp);
                }else if(c==\*\){
                    st.push(firstOp*secOp);
                }else{
                    st.push(firstOp/secOp);
                }
            }
            else{
                st.push(stoi(c));
            }
        }
        return st.top();
    }
};