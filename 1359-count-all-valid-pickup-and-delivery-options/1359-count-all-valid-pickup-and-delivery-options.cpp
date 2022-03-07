const int MOD = 1e9 + 7;

#define mul(a, b) ((a % MOD) * (b % MOD)) % MOD
long long dp[501] = { -1 };

class Solution {
public:
    int countOrders(int n) {
        if (dp[0] == -1) {
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= 500; i++) {
                dp[i] = mul(i * (2 * i - 1), dp[i - 1]);
            }
        }
        return dp[n];
    }
};