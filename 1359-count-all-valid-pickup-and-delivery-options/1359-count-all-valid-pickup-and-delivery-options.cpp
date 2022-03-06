const int MOD = 1e9 + 7;

long dp[501][501] = {{0}};

class Solution {
public:
    long solve(int n, int m) {  
        if (n > m || m < 0 || n < 0) {
            return 0;
        } else if (n == 0 && m == 0) {
            return 1;
        } else if (dp[n][m] != -1) {
            return dp[n][m];
        }
        long ans = n * solve(n - 1, m);
        ans = ans % MOD;
        ans += ((m - n) % MOD * (solve(n, m - 1)) % MOD) % MOD;
        return dp[n][m] = ans % MOD;
    }
    
    int countOrders(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, n);
    }
};