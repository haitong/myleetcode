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
 *
 * */

public class Solution {
    public int titleToNumber(String s) {
        if(s.isEmpty()) return 0;
        int bit = 1;
        int res = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            res += (s.charAt(i) - 'A' + 1) * bit;
            bit *= 26;
        }
        return res;
    }
}
