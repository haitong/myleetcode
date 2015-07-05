/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

[show hint]

Hint:
Could you do it in-place with O(1) extra space?
*/
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        if(n<=1) return;
        int shift = k%n;
        if(shift == 0) return;
        int copy[shift];
        for(int i=0; i < shift; i++){
            copy[i] = nums[n - shift + i];
        }
        for(int i=n-1; i >= shift; i--){
            nums[i] = nums[i - shift];
        }
        for(int i=0; i < shift; i++){
            nums[i] = copy[i];
        }
    }
};
