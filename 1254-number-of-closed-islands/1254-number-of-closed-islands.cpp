class Solution {
public:
    int m, n;
    
    void dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited, bool& isEnclosed) {
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || grid[x][y] == 1) {
            return;
        }
        visited[x][y] = true;
        if (x == 0 || y == 0 || x == m - 1 || y == n - 1) {
            isEnclosed = false;
        }
        dfs(grid, x + 1, y, visited, isEnclosed);
        dfs(grid, x, y + 1, visited, isEnclosed);
        dfs(grid, x - 1, y, visited, isEnclosed);
        dfs(grid, x, y - 1, visited, isEnclosed);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    bool isEnclosed = true;
                    dfs(grid, i, j, visited, isEnclosed);
                    if (isEnclosed) {
                        res++;
                    }   
                }
            }
        }
        return res;
    }
};