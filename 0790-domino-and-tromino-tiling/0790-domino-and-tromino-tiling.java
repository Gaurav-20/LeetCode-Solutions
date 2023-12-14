class Solution {
    
    static long[] dp;
    
    static {
        int MOD = 1000000007;
        dp = new long[1001];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for (int i = 4; i <= 1000; i++) {
            dp[i] = 2 * dp[i - 1] + dp[i - 3]; 
            dp[i] %= MOD;
        }
    }
    
    public int numTilings(int n) {
        return (int) dp[n];
    }
}