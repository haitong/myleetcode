/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
*/
class Solution:
    # @param s, a string
    # @return a list of strings
    def findRepeatedDnaSequences(self, s):
        dict = {"A":0, "C":1, "G":2, "T":3}
        visited = {}
        res = []
        value = 0
        for i in range(len(s)):
            value = value * 4 + dict[s[i]]
            if(i < 9):
                continue
            if value in visited:
                if visited[value] == 1:
                    res.append(s[i-9:i+1])
                visited[value] = visited[value] + 1
            else:
                visited[value] =1
            value = value & 0x3FFFF
        return res
        
