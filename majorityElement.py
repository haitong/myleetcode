'''
Given an array of size n, find the majority element. The majority element is the element that appears more than . n/2 . times.
You may assume that the array is non-empty and the majority element always exist in the array.
'''
class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        d = {}
        for i in num:
            if i in d:
                d[i] = d[i] + 1
            else:
                d[i] = 1
        
        res = 0
        count = 0
        for key, val in d.iteritems():
            if count < val:
                res = key
                count = val
        return res
