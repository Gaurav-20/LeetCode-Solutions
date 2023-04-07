class Solution {
public:
    int n, m;
    
    void traverse(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited,
                 int& count, bool& isClosed) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        count++;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            isClosed = false;
        }
        traverse(grid, i + 1, j, visited, count, isClosed);
        traverse(grid, i, j + 1, visited, count, isClosed);
        traverse(grid, i - 1, j, visited, count, isClosed);
        traverse(grid, i, j - 1, visited, count, isClosed);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (n == 1 || m == 1) {
            return 0;
        }
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    int count = 0;
                    bool isClosed = true;
                    traverse(grid, i, j, visited, count, isClosed);
                    if (isClosed) {
                        res += count;
                    }
                }
            }
        }
        return res;
    }
};