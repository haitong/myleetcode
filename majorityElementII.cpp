/*
Given an integer array of size n, find all elements that appear more than . n/3 . times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int count1=0, count2=0, candidate1=0, candidate2=1;
        for(auto n : nums){
            if(n == candidate1){
                count1++;
            }
            else if(n == candidate2){
                count2++;
            }
            else if(count1 == 0){
                count1 = 1;
                candidate1 = n;
            }
            else if(count2 == 0){
                count2 = 1;
                candidate2 = n;
            }
            else{
                count1--;
                count2--;
            }
        }
        
        count1 = 0;
        count2 = 0;
        for(auto n : nums){
            if(n == candidate1) count1++;
            else if(n == candidate2) count2++;
        }
        
        if(count1 > nums.size()/3) res.push_back(candidate1);
        if(count2 > nums.size()/3) res.push_back(candidate2);
        return res;
    }
};
