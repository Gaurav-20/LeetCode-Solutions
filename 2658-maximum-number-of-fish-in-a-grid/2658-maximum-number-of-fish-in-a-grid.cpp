class Solution {
public:
    int m, n;
    
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || grid[i][j] == 0) {
            return 0;
        }
        visited[i][j] = true;
        int res = grid[i][j];
        res += dfs(grid, i + 1, j, visited);
        res += dfs(grid, i, j + 1, visited);
        res += dfs(grid, i - 1, j, visited);
        res += dfs(grid, i, j - 1, visited);
        return res;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    res = max(res, dfs(grid, i, j, visited));
                }
            }
        }
        return res;
    }
};