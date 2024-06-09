class Solution {
    public int n;
    public int[][] dp;
    
    public int maxTotalReward(int[] rewardValues) {
        this.n = rewardValues.length;
        int sum = 0;
        for (int value : rewardValues) {
            sum += value;
        }
        this.dp = new int[n + 1][4001];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        Arrays.sort(rewardValues);
        return solve(rewardValues, 0, 0);
    }
    
    public int solve(int[] rewardValues, int idx, int sum) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }
        int result = solve(rewardValues, idx + 1, sum);
        if (rewardValues[idx] > sum) {
            result = Math.max(result,
                              rewardValues[idx] + solve(rewardValues, idx + 1, sum + rewardValues[idx]));
        }
        return dp[idx][sum] = result;
    }
}