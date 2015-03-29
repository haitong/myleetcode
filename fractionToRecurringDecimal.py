'''
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
'''
class Solution:
    # @return a string
    def fractionToDecimal(self, numerator, denominator):
        if numerator == 0:
            return '0'
        res = []
        if numerator > 0 and denominator < 0:
            res += '-'
        if numerator < 0 and denominator > 0:
            res +='-'
        num = abs(long(numerator))
        denom = abs(long(denominator))        
        
        res.append(str(num/denom))
        num = num%denom
        if num == 0:
            return ''.join(res)
        res.append(".")
        dict = {}
        
        tmp = []
        location = 0
        while True:
            residue = num*10%denom
            val = num * 10 / denom
            if num not in dict:
                dict[num] = location
                tmp.append(str(val))
            else:
                start = dict[num]
                res.extend(tmp[:start])
                res.append("(")
                res.extend(tmp[start:])
                res.append(")")
                break;
            
            location +=1
            num = residue
            if num == 0:
                res.extend(tmp)
                break
        return ''.join(res)
                
                
                
                
                
                
