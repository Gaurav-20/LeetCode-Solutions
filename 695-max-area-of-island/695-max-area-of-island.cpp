int temp;
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int x, int y, 
             int n, int m, vector<vector<bool>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 0) {
            return;
        }
        visited[x][y] = true;
        temp++;
        dfs(grid, x + 1, y, n, m, visited);
        dfs(grid, x, y + 1, n, m, visited);
        dfs(grid, x - 1, y, n, m, visited);
        dfs(grid, x, y - 1, n, m, visited);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    temp = 0;
                    dfs(grid, i, j, n, m, visited);
                    res = max(res, temp);
                }
            }
        }
        return res;
    }
};