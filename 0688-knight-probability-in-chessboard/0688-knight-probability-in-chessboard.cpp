class Solution {
public:
    double dp[26][26][102];
    
    int xMove[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
    int yMove[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
    
    double solve(int row, int col, int n, int k) {
        if (row < 0 || col < 0 || row >= n || col >= n) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        if (dp[row][col][k] != -1.0) {
            return dp[row][col][k];
        }
        double res = 0;
        for (int i = 0; i < 8; i++) {
            res += solve(row + xMove[i], col + yMove[i], n, k - 1);
        }
        return dp[row][col][k] = res;
    }

    double knightProbability(int n, int k, int row, int column) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < 102; k++) {
                    dp[i][j][k] = -1.0;
                }
            }
        }
        double favourableOutcomes = solve(row, column, n, k);
        double totalOutcomes = pow(8.0, k);
        return favourableOutcomes / totalOutcomes;
    }
};