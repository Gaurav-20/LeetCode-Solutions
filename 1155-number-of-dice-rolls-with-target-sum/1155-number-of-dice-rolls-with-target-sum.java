class Solution {
    public int numRollsToTarget(int n, int k, int target) {
        long[][] dp = new long[n + 1][target + 1];
        dp[0][0] = 1;
        int MOD = (int) 1e9 + 7;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                for (int face = 1; face <= k && face <= j; face++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - face]) % MOD;
                }
            }
        }
        return (int) dp[n][target];
    }
}