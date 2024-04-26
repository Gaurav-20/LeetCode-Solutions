class Solution {
    public int minFallingPathSum(int[][] grid) {
        int n = grid.length;
        int[][] dp = new int[n][n];
        // return solve(grid, 0, -1, dp);
        for (int i = 0; i < n; i++) {
            dp[n - 1][i] = grid[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int res = 1000000;
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        res = Math.min(res, dp[i + 1][k]);
                    }
                }
                dp[i][j] = grid[i][j] + res;
            }
        }
        int result = 1000000;
        for (int i = 0; i < n; i++) {
            result = Math.min(dp[0][i], result);
        }
        return result;
    }

    // public int solve(int[][] grid, int idx, int prevCol, Integer[][] dp) {
    //     if (idx == n) {
    //         return 0;
    //     }
    //     if (dp[idx][prevCol + 1] != null) {
    //         return dp[idx][prevCol + 1];
    //     }
    //     int minValue = 1000000;
    //     for (int it = 0; it < n; it++) {
    //         if (it != prevCol) {
    //             int value = grid[idx][it] + solve(grid, idx + 1, it, dp);
    //             minValue = Math.min(minValue, value);
    //         }
    //     }
    //     return dp[idx][prevCol + 1] = minValue;
    // }
}