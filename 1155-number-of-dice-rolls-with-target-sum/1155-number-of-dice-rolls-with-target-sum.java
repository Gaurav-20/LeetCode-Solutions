class Solution {
    public int MOD = (int) 1e9 + 7;
    public int numFaces;
    public int target;
    
    public int numRollsToTarget(int n, int k, int target) {
        this.numFaces = k;
        this.target = target;
        long[][] dp = new long[n + 1][target + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return (int) solve(n, 0, dp);
    }
    
    public long solve(int n, int sum, long[][] dp) {
        if (n == 0) {
            return (sum == target) ? 1 : 0;
        }
        if (sum < 0 || sum > target) {
            return 0;
        }
        if (dp[n][sum] != -1) {
            return dp[n][sum];
        }
        long result = 0;
        for (int face = 1; face <= numFaces; face++) {
            result = (result + solve(n - 1, sum + face, dp)) % MOD;
        }
        return dp[n][sum] = result % MOD;
    }
}