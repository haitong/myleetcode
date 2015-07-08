/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/
class Solution {
public:
    void combination(vector<int>& candidates, int start, vector<int>& curr, int target, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        if(start >= candidates.size() || target < 0) return;

        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            combination(candidates, i+1, curr, target-candidates[i], res);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combination(candidates,0, curr, target, res);
        return res;
    }
};


