class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIter = 0, tIter = 0;
        int sLen = s.size(), tLen = t.size();
        if (tLen < sLen) {
            return false;
        }
        while (tIter < tLen) {
            if (sIter < sLen && s[sIter] == t[tIter]) {
                sIter++;
            }
            tIter++;
        }
        return sIter == sLen;
    }
};