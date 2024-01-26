class Solution {
    public int[][][] dp;
    public int rows, cols;
    public static int MOD = 1000000007;
    
    public int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this.rows = m;
        this.cols = n;
        dp = new int[m][n][maxMove];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < maxMove; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        return solve(maxMove, startRow, startColumn, 0);
    }
    
    public int solve(int maxMoves, int x, int y, int moves) {
        if (x < 0 || y < 0 || x >= rows || y >= cols) {
            return 1;
        }
        if (moves == maxMoves) {
            return 0;
        }
        if (dp[x][y][moves] != -1) {
            return dp[x][y][moves];
        }
        int res = 0;
        res = (res + solve(maxMoves, x + 1, y, moves + 1)) % MOD;
        res = (res + solve(maxMoves, x - 1, y, moves + 1)) % MOD;
        res = (res + solve(maxMoves, x, y + 1, moves + 1)) % MOD;
        res = (res + solve(maxMoves, x, y - 1, moves + 1)) % MOD;
        return dp[x][y][moves] = res;
    }
}