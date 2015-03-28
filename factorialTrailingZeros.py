'''
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
'''
class Solution:
    # @return an integer
    def trailingZeroes(self, n):
        if n <= 0:
            return 0
        count = 0
        while n >= 5:
            count += n/5
            n /= 5
        return count
