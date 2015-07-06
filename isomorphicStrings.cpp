/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size()) return false;
        
        unordered_map<char, char> dict;
        unordered_set<char> visited;
        for(int i = 0; i < s.size(); i++){
            if(dict.find(s[i]) == dict.end()){
                if(visited.find(t[i]) == visited.end()){
                    dict[s[i]] = t[i];
                    visited.insert(t[i]);
                }
                else return false;
            }
            else if(dict[s[i]] != t[i]){
                return false;
            }
        }
        return true;
    }
};
