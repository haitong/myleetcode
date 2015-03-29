'''
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
'''
class Solution:
    # @return a string
    def convertToTitle(self, num):
        title = []
        while num > 0:
            c = (num-1)%26
            title.append(chr(ord('A') + c))
            num = (num-1)/26
        return ''.join(reversed(title))
