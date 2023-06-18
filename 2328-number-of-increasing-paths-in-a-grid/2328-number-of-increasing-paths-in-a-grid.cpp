const long long MOD = 1e9 + 7;

vector<int> dir = { 0, 1, 0, -1, 0 };

class Solution {
public:
    int rows, cols;

    long long solve(vector<vector<int>>& mat, int r, int c, vector<vector<long long>>& dp) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) {
            return 0;
        }
        if (dp[r][c] != -1) {
            return dp[r][c];
        }
        long long res = 1;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i], nc = c + dir[i + 1];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && mat[nr][nc] > mat[r][c]) {
                res = (res + solve(mat, nr, nc, dp)) % MOD;
            }
        }
        return dp[r][c] = (res % MOD);
    }
    
    int countPaths(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size();
        vector<vector<long long>> dp(rows, vector<long long>(cols, -1LL));
        long long res = 0;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                solve(matrix, row, col, dp);
                res = (res + dp[row][col]) % MOD;
            }
        }
        return res;
    }
};