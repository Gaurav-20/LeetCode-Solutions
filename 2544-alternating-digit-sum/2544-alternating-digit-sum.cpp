class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int len = s.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (i & 1) {
                res -= s[i] - '0';
            } else {
                res += s[i] - '0';
            }
        }
        return res;
    }
};