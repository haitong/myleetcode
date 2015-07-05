/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
*/
class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t pos1 = 0, pos2 = 0;
        size_t pre1 = -1, pre2 = -1;
        int v1 = 0, v2 = 0;
        do{
            v1 = 0;
            v2 = 0;
            if(pos1 != string::npos){
                pos1 = version1.find_first_of('.',pre1+1);
                v1=stoi(version1.substr(pre1+1,pos1-pre1-1));
            }
            if(pos2 != string::npos){
                pos2 = version2.find_first_of('.',pre2+1);
                v2=stoi(version2.substr(pre2+1,pos2-pre2-1));
            }       
            pre1 = pos1;
            pre2 = pos2;
            if(v1 < v2) return -1;
            if(v1 > v2) return 1;
        }while(pos1 != string::npos || pos2 != string::npos);
        return 0;
    }
};
