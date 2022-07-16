int dp[55][55][55];
const int MOD = 1e9 + 7;

class Solution {
public:
    int rows, cols;
    
    int solve(int maxMoves, int x, int y, int moves) {
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
    
    int findPaths(int m, int n, int maxMoves, int startRow, int startColumn) {
        rows = m, cols = n;
        memset(dp, -1, sizeof(dp));
        return solve(maxMoves, startRow, startColumn, 0);
    }
};