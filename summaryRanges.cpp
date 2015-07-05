/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.empty()) return res;
        if(nums.size() == 1){
            res.push_back(std::to_string(nums[0]));
            return res;
        }
        int start = nums[0];
        int end = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != end + 1){
                if(start == end){
                    res.push_back(std::to_string(start));
                }
                else{
                    string s;
                    s = std::to_string(start);
                    s += "->";
                    s += std::to_string(end);
                    res.push_back(s);
                }
                start = nums[i];
                end = nums[i];                
            }
            else{
                end = nums[i];
            }
        }
        if(start == end){
            res.push_back(std::to_string(start));
        }
        else{
            string s;
            s = std::to_string(start);
            s += "->";
            s += std::to_string(end);
            res.push_back(s);
        }        
        return res;
    }
};
