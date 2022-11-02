class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size(), m = t.size();
        int sptr = 0, tptr = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '#') {
                if (sptr > 0) {
                    sptr--;
                }
            } else {
                s[sptr++] = s[i];
            }
        }
        for (int i = 0; i < m; i++) {
            if (t[i] == '#') {
                if (tptr > 0) {
                    tptr--;
                }
            } else {
                t[tptr++] = t[i];
            }
        }
        if (tptr != sptr) {
            return false;
        }
        for (int i = 0; i < sptr; i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};