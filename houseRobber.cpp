/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {
public:
    void maxRob(vector<int> & nums, int index, int & res, int curr){
        if(index >= nums.size()){
            if(res < curr) res = curr;
            return;
        }
        for(int i = index; i < nums.size(); i++){
            // rob current house
            maxRob(nums, i + 2, res, curr + nums[index]);
            // do not rob current house
            maxRob(nums, i + 1, res, curr);
        }
    }
    int rob(vector<int>& nums) {
        int res = 0;
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
 //        maxRob(nums, 0, res, 0);
        vector<int> result(nums.size(), 0);   
        result[0] = nums[0];
        result[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            result[i] = max(result[i-1], result[i-2] + nums[i]);
        }
        return result.back();
    }
};
