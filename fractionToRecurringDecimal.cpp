/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
 * */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res;
        if (numerator == 0) return "0";
        if((numerator < 0 && denominator > 0)
        || (numerator > 0 && denominator < 0)){
            res.append("-");
        }
        
        long num = abs((long)numerator);
        long denom = abs((long)denominator);
        
        res.append(std::to_string(num/denom));
        if(num%denom == 0) return res;
        res.append(".");
        num = num%denom;
        
        string tmp;
        map<long,int> locationMap;
        int location = 0;
        while(true){
            long residue = num*10%denom;
            long val = num * 10 / denom;
            if(locationMap.find(num) == locationMap.end()){ 
                tmp.append(std::to_string(val));
                locationMap[num] = location;
            }
            else{
  //            adding parathensis
                int start = locationMap.find(num)->second;
                res.append(tmp.substr(0,start));
                res.append("(");
                res.append(tmp.substr(start,location - start));
                res.append(")");
                break;
            }
            location++;
            num = residue;
            if(num == 0){
  //              adding to res string
                res.append(tmp);
                break;
            }
        }
        return res;
    }
};
