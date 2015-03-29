/*
Given an array of size n, find the majority element. The majority element is the element that appears more than . n/2 . times.

You may assume that the array is non-empty and the majority element always exist in the array.
 * */
class Solution {
public:
    int majorityElement(vector<int> &num) {
        unordered_map<int,int> h;
        for(int i : num){
            h[i] = h[i] + 1;
        }
        int res = 0, count = 0;
        for(auto it = h.begin(); it != h.end(); it++){
            if(count < it->second){
                count = it->second;
                res = it->first;
            }
        }
        return res;
    }
};
