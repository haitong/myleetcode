/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int start = 0, end;
        int sum = 0;
        int res = INT_MAX;
        for(end = 0; end < nums.size(); end++){
            sum += nums[end];
            
            while(sum >= s){
                int len = end - start + 1;
                res = min(res,len);
                sum -= nums[start];
                start++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};
