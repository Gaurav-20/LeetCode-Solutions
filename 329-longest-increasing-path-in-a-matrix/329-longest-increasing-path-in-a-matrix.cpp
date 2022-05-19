vector<int> dir = { 0, 1, 0, -1, 0 };

class Solution {
public:
    int rows, cols;

    int solve(vector<vector<int>>& mat, int r, int c, vector<vector<int>>& dp) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        int res = 0;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i], nc = c + dir[i + 1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] > mat[r][c]) {
                res = max(res, 1 + solve(mat, nr, nc, dp));
            }
        }
        return dp[r][c] = max(res, 1);
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