// A palindrome of length 5 is of the form xy_yx, whee _ means any digit
const int MOD = 1e9 + 7;

class Solution {
public:
    int countPalindromes(string s) {
        int n = s.size();
        long long res = 0;
        for (int x = 0; x <= 9; x++)  {
            for (int y = 0; y <= 9; y++) {
                vector<int> pattern = { x, y, 0, y, x };
                vector<long long> dp(6);
                dp[5] = 1; 
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 5; j++) {
                        if ((pattern[j] == s[i] - '0') || j == 2) {
                            dp[j] = (dp[j] + dp[j + 1]) % MOD;
                        }
                    }
                }
                res = (res + dp[0]) % MOD; 
            }
        }
        return res;
    }
};