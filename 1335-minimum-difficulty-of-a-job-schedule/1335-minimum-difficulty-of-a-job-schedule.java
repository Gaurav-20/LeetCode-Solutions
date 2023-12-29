class Solution {
    public int minDifficulty(int[] jobDifficulty, int days) {
        int len = jobDifficulty.length;
        if (len < days) {
            return -1;
        }
        int[] dp = new int[len + 1];
        Arrays.fill(dp, 1000000000);
        dp[len] = 0;
        for (int d = 1; d <= days; d++) {
            for (int i = 0; i <= len - d; i++) {
                int maxd = 0;
                dp[i] = 1000000000;
                for (int j = i; j <= len - d; j++) {
                    maxd =  Math.max(maxd, jobDifficulty[j]);
                    dp[i] = Math.min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return dp[0];
    }
}