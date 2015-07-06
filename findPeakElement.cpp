/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -∞.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

click to show spoilers.

Note:
Your solution should be in logarithmic complexity.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() < 2) return 0;
        int left = 0, right = nums.size()-1;
        int mid;
        while(left < right){
            mid = (right - left)/2 + left;
            if(nums[mid] > nums[mid+1]){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
};
