/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/
bool compare(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 + s2 > s2 + s1;
}

class Solution {
public:
    string largestNumber(vector<int> &num) {
        sort(num.begin(), num.end(), compare);
        string res, tmp;
        for(int i=0; i < num.size(); i++){
            if(num[i] == 0 && res.empty()) continue;
            tmp = to_string(num[i]);
            res += tmp;
        }
        if(res.empty()) return "0";
        return res;
    }
};

