/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
Note: Do not use the eval built-in library function.
*/
class Solution {
public:
    int cal(int oper1, int oper2, char c){
        switch(c){
            case '+': return oper1 + oper2;
            case '-': return oper1 - oper2;
            case '*': return oper1 * oper2;
            case '/': return oper1 / oper2;
        }
    }
    int calculate(string s) {
        if(s.empty()) return 0;
        s += '+';
        stack<int> operand;
        stack<char> operation;
        int curr(0);
        for(auto c : s){
            if(c == ' ') continue;
            if(c >= '0' && c <= '9'){
                curr = curr * 10 + c - '0';
            }
            else{
                if(c == '+' || c == '-'){
                    while(!operation.empty() && !operand.empty()){
                        curr = cal(operand.top(), curr, operation.top());
                        operand.pop();
                        operation.pop();
                    }
                    operand.push(curr);
                    operation.push(c);
                }
                else if(c == '*' || c == '/'){
                    if(operation.empty() || (operation.top() != '*' && operation.top() != '/')){
                        operand.push(curr);
                        operation.push(c); 
                        curr = 0;
                        continue;
                    }
                    curr = cal(operand.top(),curr,operation.top());
                    operand.pop();
                    operation.pop(); 
                    operand.push(curr);
                    operation.push(c);
                }
                curr = 0;
            }
        }
        return operand.top();
    }
};
