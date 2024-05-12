class Solution {
    public int maximumEnergy(int[] energy, int k) {
        int n = energy.length;
        int[] dp = new int[n];
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            dp[i] = energy[i];
            if (i - k >= 0 && dp[i - k] > 0) {
                dp[i] += dp[i - k];
            }
            if (i + k >= n) {
                result = Math.max(dp[i], result);
            }
        }
        return result;
    }
}