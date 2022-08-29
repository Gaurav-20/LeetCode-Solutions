class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y,
            vector<vector<bool>>& visited, bool& flag) {
        if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || grid2[x][y] == 0) {
            return;
        }
        visited[x][y] = true;
        if (grid1[x][y] == 0) {
            flag = false;
        }
        dfs(grid1, grid2, x + 1, y, visited, flag);
        dfs(grid1, grid2, x, y + 1, visited, flag);
        dfs(grid1, grid2, x - 1, y, visited, flag);
        dfs(grid1, grid2, x, y - 1, visited, flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int subIslands = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool flag = true;
                    dfs(grid1, grid2, i, j, visited, flag);
                    if (flag) {
                        subIslands++;
                    }
                }
            }
        }
        return subIslands;
    }
};