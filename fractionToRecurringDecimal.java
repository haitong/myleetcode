/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
*/
public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        StringBuilder res = new StringBuilder();
        if(numerator == 0) return "0";
        long num = (long) numerator;
        long denom = (long) denominator;
        if((num < 0 && denom > 0)
        || (num > 0 && denom < 0)){
            res.append("-");
        }
        
        num = Math.abs(num);
        denom = Math.abs(denom);
        
        res.append(num/denom);
        
        num = num%denom;
        if(num == 0) return res.toString();
        res.append(".");
        HashMap<Long,Integer> locationMap = new HashMap<Long,Integer>();
        int location = 0;
        StringBuilder tmp = new StringBuilder();
        while(true){
            long residue = num*10%denom;
            long val = num*10/denom;
            if(!locationMap.containsKey(num)){
                locationMap.put(num,location);
                tmp.append(val);
            }
            else{
                int start = locationMap.get(num);
                res.append(tmp.substring(0,start));
                res.append("(");
                res.append(tmp.substring(start,location));
                res.append(")");
                break;
            }
            num = residue;
            if(num == 0){
                res.append(tmp);
                break;
            }
            location++;
        }
        return res.toString();
    }
}
