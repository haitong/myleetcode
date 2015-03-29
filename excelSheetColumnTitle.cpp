/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 * */
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0){
            int d = (n-1)%26;
            char c = (char)(d + 'A');
            res.append(1,c);
            n = (n-1)/26;
        }
        std::reverse(res.begin(),res.end());
        return res;
    }
};
