class Solution {
    public static final int MOD = 1000000007;
    
    public int knightDialer(int n) {
        int[] dp = new int[10];
        for (int button = 0; button < 10; button++) {
            dp[button] = 1;
        }
        for (int len = 2; len <= n; len++) {
            int[] dpCopy = new int[10];
            dpCopy[0] = (dp[4] + dp[6]) % MOD;
            dpCopy[1] = (dp[6] + dp[8]) % MOD;
            dpCopy[2] = (dp[7] + dp[9]) % MOD;
            dpCopy[3] = (dp[4] + dp[8]) % MOD;
            dpCopy[4] = ((dp[0] + dp[3]) % MOD + dp[9]) % MOD;
            dpCopy[5] = 0;
            dpCopy[6] = ((dp[0] + dp[1]) % MOD + dp[7]) % MOD;
            dpCopy[7] = (dp[2] + dp[6]) % MOD;
            dpCopy[8] = (dp[1] + dp[3]) % MOD;
            dpCopy[9] = (dp[2] + dp[4]) % MOD;
            dp = dpCopy;
        }
        int res = 0;
        for (int button = 0; button < 10; button++) {
            res = (res + dp[button]) % MOD;
        }
        return res;
    }
}