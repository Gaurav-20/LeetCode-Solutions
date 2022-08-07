class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j - 1, visited);
    }
    
    int countIslands(vector<vector<int>>& grid) {
        int islands = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }
        return islands;
    }
    
    int minDays(vector<vector<int>>& grid) {
        // requirement is that number of islands > 1 (or zero)
        n = grid.size();
        m = grid[0].size();
        int islands = countIslands(grid);
        if (islands != 1) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                } else {
                    grid[i][j] = 0;
                    islands = countIslands(grid);
                    grid[i][j] = 1;
                    if (islands != 1) {
                        return 1;
                    }
                }
            }
        }
        return 2;
    }
};