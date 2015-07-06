/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
*/
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        if(nums.size() == 2) return abs(nums[1] - nums[0]);
        vector<int> high(nums.size(), INT_MIN);
        vector<int> low(nums.size(), INT_MAX);
        int max_number = *max_element(nums.begin(), nums.end());
        int min_number = *min_element(nums.begin(), nums.end());
        double step = (double)(max_number - min_number)/(nums.size() - 1);
        for(auto num : nums){
            int index = (num - min_number)/step;
            high[index] = max(high[index], num);
            low[index] = min(low[index], num);
        }
        
        int res = 0;
        int prev = high[0];
        for(int i = 1; i < nums.size(); i++){
            if(low[i] != INT_MAX){
                res = max(res, low[i] - prev);
                prev = high[i];
            }
        }
        return res;
    }
};
