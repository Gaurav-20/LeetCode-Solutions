class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] dp = new int[n + 1];
        for (int idx = n - 1; idx >= 0; idx--) {
            int maxSum = 0;
            int maxNum = 0;
            for (int i = idx; i < Math.min(arr.length, idx + k); i++) {
                maxNum = Math.max(maxNum, arr[i]);
                maxSum = Math.max(maxSum, maxNum * (i - idx + 1) + dp[i + 1]);
            }
            dp[idx] = maxSum;
        }
        return dp[0];
    }
}