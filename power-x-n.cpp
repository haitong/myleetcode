/*
Implement pow(x, n).
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        bool negative = false;
        unsigned int power = n;
        if(n < 0){
            power = -n;
            negative = true;
        }
        double res = 1, curr = x;
        while(power!=0){
            if(power & 1) res *= curr;
            curr *= curr;
            power >>= 1;
        }
        if(negative) return 1/res;
        return res;
    }
};
