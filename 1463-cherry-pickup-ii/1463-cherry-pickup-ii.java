class Solution {
    public int rows;
    public int cols;
    public int[][][] dp;
    
    public int cherryPickup(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        this.dp = new int[rows][cols][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                for (int k = 0; k < cols; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(grid, 0, 0, cols - 1);
    }
    
    public int solve(int[][] grid, int i, int j, int k) {
        if (i == rows || j < 0 || k < 0 || j >= cols || k >= cols) {
            return 0;
        }
        if (dp[i][j][k] != -1) {
            return dp[i][j][k];
        }
        int result = 0;
        for (int dj = -1; dj <= 1; dj++) {
            for (int dk = -1; dk <= 1; dk++) {
                result = Math.max(result, solve(grid, i + 1, j + dj, k + dk));
            }
        }
        if (j == k) {
            result += grid[i][j];
        } else {
            result += grid[i][j] + grid[i][k];
        }
        return dp[i][j][k] = result;
    }
}