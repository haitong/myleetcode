'''
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
'''
class Solution:
    # @param s, a string
    # @return an integer
    def titleToNumber(self, s):
        if len(s) == 0:
            return 0
        bit = 1
        res = 0
        for i in reversed(range(len(s))):
            res += bit * (ord(s[i]) - ord('A') + 1)
            bit *= 26
            
        return res
