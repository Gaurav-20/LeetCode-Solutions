class Solution {
public:
    int rows, cols;
    
    int solve(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& dp) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int up = 0, down = 0, left = 0, right = 0;
        if (r > 0 && matrix[r - 1][c] > matrix[r][c]) {
            up = 1 + solve(matrix, r - 1, c, dp);
        }
        if (r < rows - 1 && matrix[r + 1][c] > matrix[r][c]) {
            down = 1 + solve(matrix, r + 1, c, dp);
        }
        if (c > 0 && matrix[r][c - 1] > matrix[r][c]) {
            left = 1 + solve(matrix, r, c - 1, dp);
        }
        if (c < cols - 1 && matrix[r][c + 1] > matrix[r][c]) {
            right = 1 + solve(matrix, r, c + 1, dp);
        }
        return dp[r][c] = max({ up, down, left, right, 1 });
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        int res = 1;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                res = max(res, solve(matrix, row, col, dp));
            }
        }
        return res;
    }
};