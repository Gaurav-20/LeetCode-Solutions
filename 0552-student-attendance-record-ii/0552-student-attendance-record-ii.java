class Solution {
    
    public static final int MOD = 1000000007;

    public int checkRecord(int n) {
        long[][][] dp = new long[n + 1][2][3];
        for (long[][] x : dp) {
            for (long[] y : x) {
                Arrays.fill(y, -1);
            }
        }
        return solve(n, 1, 2, dp);
    }
    
    public int solve(int n, int A, int L, long[][][] dp) {
        if (n == 0) {
            return 1;
        }
        if (dp[n][A][L] != -1) {
            return (int) dp[n][A][L];
        }

        int res = solve(n - 1, A, 2, dp) % MOD;
        if (A > 0) {
            res = (res % MOD + solve(n - 1, A - 1, 2, dp) % MOD) % MOD;
        }
        if (L > 0) {
            res = (res % MOD + solve(n - 1, A, L - 1, dp) % MOD) % MOD;
        }

        return (int) (dp[n][A][L] = res % MOD);
    }
    
}