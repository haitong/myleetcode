/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/
class Solution {
public:
    int find(vector<int> & nums, int k, int start, int end){
        int pivot = nums[end];
        int store = start;
        for(int i = start; i < end; i++){
            if(nums[i] > pivot){
                swap(nums[i],nums[store]);
                store++;
            }
        }
        swap(nums[end],nums[store]);
        if(store - start == k) return pivot;
        else if(store - start < k) return find(nums, k - store + start-1, store+1, end);
        else return find(nums, k, start, store-1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return find(nums,k-1,0,nums.size()-1);
    }
};
