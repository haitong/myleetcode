/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/
class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.first < b.first ? true : a.second < b.second;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty() || k < 1) return false;
        vector<pair<int, int> > data;
        for(int i=0; i < nums.size(); i++){
            data.push_back(make_pair(nums[i],i));
        }
        sort(data.begin(), data.end(), Solution::compare);
        for(int i = 0; i < data.size(); i++){
            for(int j = i + 1; j < data.size(); j++){
                if(data[j].first - data[i].first <= t){
                    if(abs(data[j].second - data[i].second) <= k) return true;
                }
                else break;
            }
        }
        return false;        
    }
};
