class Solution {
public:
    int appendCharacters(string s, string t) {
        int it = 0;
        for (int is = 0; is < s.size(); is++) {
            if (s[is] == t[it]) {
                it++;
            }
        }
        return t.size() - it;
    }
};