class Solution {
    public int n;
    
    public int minFallingPathSum(int[][] grid) {
        this.n = grid.length;
        Integer[][] dp = new Integer[n + 5][n + 5];
        return solve(grid, 0, -1, dp);
    }

    public int solve(int[][] grid, int idx, int prevCol, Integer[][] dp) {
        if (idx == n) {
            return 0;
        }
        if (dp[idx][prevCol + 1] != null) {
            return dp[idx][prevCol + 1];
        }
        int minValue = 1000000;
        for (int it = 0; it < n; it++) {
            if (it != prevCol) {
                int value = grid[idx][it] + solve(grid, idx + 1, it, dp);
                minValue = Math.min(minValue, value);
            }
        }
        return dp[idx][prevCol + 1] = minValue;
    }
}