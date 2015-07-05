/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2 || k < 1) return 0;
        if(k >= prices.size()/2){
            int res = 0;
            for(int i = 1; i < prices.size(); i++){
                res += max(0,prices[i] - prices[i-1]);
            }
            return res;
        }
/*        int dp[k*2+1] = {0};
        for(int i = 0; i < prices.size(); i++){
            for(int j = min(2*k, i+1); j > 0; j--){
                dp[j] = max(dp[j], dp[j-1]+j%2?prices[i] : -prices[i]);
            }
        }
        
        int res = 0;
        for(int i = 0; i < k*2+1; i++){
            res = max(res, dp[i]);
        }
        return res;
*/
        int local[k+1] = {0};
        int global[k+1] = {0};
        
        for(int i = 1; i < prices.size(); i ++){
            int diff = prices[i] - prices[i-1];
            for(int j = k; j >= 1; j --){
                local[j] = max(global[j-1] + max(diff,0), local[j] + diff);
                global[j] = max(local[j],global[j]);
            }
        }
        return global[k];
    }
};
