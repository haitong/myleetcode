/*
 Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
 * */
class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty()) return 0;
        int res = 0;
        int bit = 1;
        for(int i = s.size() - 1; i >=0; i--){
            res += (s[i] - 'A' + 1) * bit;
            bit *= 26;
        }
        return res;
    }
};
