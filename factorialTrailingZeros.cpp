/*
 *Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
 * */
class Solution {
public:
    int trailingZeroes(int n) {
        if (n<=0) return 0;
        int count = 0;
        for (int i=5;; i*=5) {
            count += n / i;
            if (n/i <= 1) break;
        }        
        return count;
    }
};
