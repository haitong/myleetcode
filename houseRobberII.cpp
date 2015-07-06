/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        
        vector<int> rob_first(nums.size(), 0);
        vector<int> not_rob_first(nums.size(), 0);
        
        rob_first[0] = nums[0];
        rob_first[1] = nums[0];
        for(int i = 2; i < nums.size()-1; i++){
            rob_first[i] = max(nums[i] + rob_first[i-2], rob_first[i-1]);
        }
        
        not_rob_first[1] = nums[1];
        for(int i = 2; i < nums.size(); i ++){
            not_rob_first[i] = max(nums[i] + not_rob_first[i-2], not_rob_first[i-1]);
        }
        
        return max(not_rob_first.back(), rob_first[nums.size() - 2]);
        
    }
};
