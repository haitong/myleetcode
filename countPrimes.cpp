/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;

        vector<bool> data(n-2, false);
        int res = 0;
        for(int start = 0; start < n - 2; start ++){
            if(!data[start]) {
                res++;
                int val = start + 2;
                val += start + 2;
                while(val < n){
                    data[val - 2] = true;
                    val += start + 2;
                }
            }
        }
        
        return res;
    }
};
