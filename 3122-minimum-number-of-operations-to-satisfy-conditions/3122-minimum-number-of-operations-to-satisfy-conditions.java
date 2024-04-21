class Solution {
    public int m;
    public int n;
    
    public int minimumOperations(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        int[][] freq = new int[n][10];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = grid[i][j];
                freq[j][curr] += 1;
            }
        }
        int[][] dp = new int[n][11];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(grid, dp, 0, freq, 10);
    }
    
    public int solve(int[][] grid, int[][] dp, int col, int[][] freq, int prev) {
        if (col >= n) {
            return 0;
        }
        if (dp[col][prev] != -1) {
            return dp[col][prev];
        }
        int mini = 10000000;
        for (int curr = 0; curr < 10; curr++) {
            if (curr != prev) {
                int changes = getChangesCount(freq, col, curr);
                mini = Math.min(mini, changes + solve(grid, dp, col + 1, freq, curr));
            }
        }
        return dp[col][prev] = mini;
    }
    
    public int getChangesCount(int[][] freq, int col, int curr) {
        int changes = 0;
        for (int el = 0; el < 10; el++) {
            if (el != curr) {
                changes += freq[col][el];
            }
        }
        return changes;
    }
}