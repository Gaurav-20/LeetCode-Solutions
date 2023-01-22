/*
    i, j => i, j
    0, 0 => 0, 0 - we can't select both zeros as they give same output
    0, 1 => 1, 1
    1, 0 => 1, 1
    1, 1 => 1, 0
*/

class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if (s == target) {
            return true;
        }
        int n = s.size(), corr = 0, ct = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != target[i]) {
                ct++;
            }
            if (s[i] == '1') {
                corr++;
            }
        }
        string check = "";
        for (int i = 0; i < n; i++) {
            check += '0';
        }
        return corr > 0 && target != check;
    }
};