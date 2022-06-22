class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }
        int it = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] == s[it]) {
                it++;
            }
        }
        return (it == s.size());
    }
};