/*
Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b){
        return a.first < b.first ? true : a.second < b.second;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.empty() || k < 1) return false;
        vector<pair<int, int> > data;
        for(int i=0; i < nums.size(); i++){
            data.push_back(make_pair(nums[i],i));
        }
        sort(data.begin(), data.end(), Solution::compare);
        for(int i = 1; i < data.size(); i++){
            if(data[i-1].first == data[i].first && data[i].second - data[i-1].second <= k) return true;
        }
        return false;
    }
};
