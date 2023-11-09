const int MOD = 1e9 + 7;

class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        long long res = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            long long ct = 0;
            while (i < n && c == s[i]) {
                ct++;
                i++;
            }
            res = res + ct * (ct + 1) / 2;
            res %= MOD;
            if (i < n) {
                i--;
            }
        }
        return (int) res;
    }
};