class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char>expressions;
        stack<char>operations;
        for(int i=0;i<expression.size();++i){
            if(expression[i]=='|'||expression[i]=='&'||expression[i]=='!')
                operations.push(expression[i]);
            else if(expression[i]!=')'){
                if(expression[i]==',')
                    continue;
                else
                    expressions.push(expression[i]);
            }
            else // expression [i] == )
            {
                bool res;
                if(operations.top()=='|'){
                    res = 0;
                    while(expressions.top()!='('){
                        res |= expressions.top() == 't';
                        expressions.pop();
                    }
                }
                else if(operations.top()=='&'){
                    res = 1;
                    while(expressions.top()!='('){
                        res &= expressions.top() == 't';
                        expressions.pop();
                    }
                }
                else{
                    res =expressions.top()=='f';
                    expressions.pop();
                }
                char exp = res==1?'t':'f';
                expressions.pop();
                expressions.push(exp);
                operations.pop();
            }
        }
        return expressions.top()=='t';
    }
};