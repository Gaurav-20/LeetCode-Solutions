class Solution {
public:
    // long long solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    //     if (i == 0 && j == 0) {
    //         return dp[0][0] = grid[0][0];
    //     }
    //     if (i < 0 || j < 0) {
    //         return INT_MAX;
    //     }
    //     if (dp[i][j] != -1) {
    //         return dp[i][j];
    //     }
    //     long long up = grid[i][j] + solve(grid, i - 1, j, dp);
    //     long long left = grid[i][j] + solve(grid, i, j - 1, dp);
    //     return dp[i][j] = min(up, left);
    // }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, 0));
        // return (int) solve(grid, m - 1, n - 1, dp);
        // dp[0][0] = grid[0][0];
        // for (int i = 1; i < m; i++) {
        //     dp[i][0] = dp[i - 1][0] + grid[i][0];
        // }
        // for (int j = 1; j < n; j++) {
        //     dp[0][j] = dp[0][j - 1] + grid[0][j];
        // }
        // for (int i = 1; i < m; i++) {
        //     for (int j = 1; j < n; j++) {
        //         dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        //     }
        // }
        // return dp[m - 1][n - 1];
        vector<int> dp(m, grid[0][0]);
        for (int i = 1; i < m; i++) {
            dp[i] = dp[i - 1] + grid[i][0];
        }
        for (int j = 1; j < n; j++) {
            dp[0] += grid[0][j]; 
            for (int i = 1; i < m; i++) {
                dp[i] = min(dp[i - 1], dp[i]) + grid[i][j];
            }
        }
        return dp.back();
    }
};