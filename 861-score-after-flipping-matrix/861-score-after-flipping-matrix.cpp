class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = (1 << (m - 1)) * n;
        for (int j = 1; j < m; j++) {
            int curr = 1 << (m - j - 1);
            int setBits = 0;
            for (int i = 0; i < n; i++) {
                setBits += grid[i][j] == grid[i][0];
            }
            res += max(setBits, n - setBits) * curr;
        }
        return res;
    }
};