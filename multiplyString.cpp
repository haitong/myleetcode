/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size() + num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        int mul = 0;
        int val;
        for(int i=0; i < num1.size(); i++){
            mul = num1[i] - '0';
            carry = 0;
            string curr;
            for(int j = 0; j < num2.size(); j++){
                val = carry + (num2[j]-'0')*mul;
                carry = val/10;
                val %= 10;
                curr.push_back(val);
            }
            if(carry)curr.push_back(carry);
            carry = 0;
            for(int k = i; k - i < curr.size(); k++){
                val = res[k] - '0' + curr[k - i] + carry;
                carry = val/10;
                val %= 10;
                res[k] = val + '0';
            }
            if(carry) res[i+curr.size()] = res[i+curr.size()] + carry;
        }
        while(res.back() == '0'){ res.pop_back();}
        if(res.empty()) return "0";
        reverse(res.begin(), res.end());
        return res;
    }
};
