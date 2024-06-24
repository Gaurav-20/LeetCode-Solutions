class Solution {
    public double knightProbability(int n, int k, int row, int col) {
        Double[][][] dp = new Double[n][n][k + 1];
        return solve(row, col, k, n, dp);
    }
    
    public double solve(int row, int col, int k, int n, Double[][][] dp) {
        if (row < 0 || col < 0 || row >= n || col >= n || k < 0) {
            return 0.0;
        }
        if (k == 0) {
            return 1.0;
        }
        if (dp[row][col][k] != null) {
            return dp[row][col][k];
        }
        return dp[row][col][k] =
            solve(row - 2, col - 1, k - 1, n, dp) / 8.0 +
            solve(row - 1, col - 2, k - 1, n, dp) / 8.0 +
            solve(row + 1, col - 2, k - 1, n, dp) / 8.0 +
            solve(row + 2, col - 1, k - 1, n, dp) / 8.0 +
            solve(row + 2, col + 1, k - 1, n, dp) / 8.0 +
            solve(row + 1, col + 2, k - 1, n, dp) / 8.0 +
            solve(row - 1, col + 2, k - 1, n, dp) / 8.0 +
            solve(row - 2, col + 1, k - 1, n, dp) / 8.0;
    }
}