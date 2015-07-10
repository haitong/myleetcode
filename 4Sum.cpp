/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4) return  res;
        sort(nums.begin(), nums.end());
        int left, right;
        for(int i=0; i < nums.size()-3; i++){
            if(i>0 && nums[i-1] == nums[i]) continue;
            long val = target - nums[i];
            for(int j=i + 1; j < nums.size()-2; j++){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                val -= nums[j];
                left = j+1;
                right = nums.size()-1;
                while(left < right){
                    if(val == (nums[left] + nums[right])){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        res.push_back(tmp);
                        do {
                            left++;
                        } while(left < right && nums[left-1] == nums[left]);     
                        do {
                            right--;
                        } while(right > left && nums[right] == nums[right+1]);                        
                    }
                    else if(val < nums[left] + nums[right]){
                        do {
                            right--;
                        } while(right > left && nums[right] == nums[right+1]);
                    }
                    else{
                        do {
                            left++;
                        } while(left < right && nums[left-1] == nums[left]);
                    }
                }
                val += nums[j];
            }
        }
        return res;
    }
};
