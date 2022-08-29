class Solution {
public:
    int n, m;
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y, bool& flag) {
        if (x < 0 || y < 0 || x >= n || y >= m || grid2[x][y] != 1) {
            return;
        }
        grid2[x][y] = 2;
        if (grid1[x][y] == 0) {
            flag = false;
        }
        dfs(grid1, grid2, x + 1, y, flag);
        dfs(grid1, grid2, x, y + 1, flag);
        dfs(grid1, grid2, x - 1, y, flag);
        dfs(grid1, grid2, x, y - 1, flag);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int subIslands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    bool flag = true;
                    dfs(grid1, grid2, i, j, flag);
                    if (flag) {
                        subIslands++;
                    }
                }
            }
        }
        return subIslands;
    }
};