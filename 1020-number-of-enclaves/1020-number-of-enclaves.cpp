class Solution {
public:
    int n, m;
    
    // void traverse(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited,
    //              int& count, bool& isClosed) {
    //     if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == 0) {
    //         return;
    //     }
    //     visited[i][j] = true;
    //     count++;
    //     if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
    //         isClosed = false;
    //     }
    //     traverse(grid, i + 1, j, visited, count, isClosed);
    //     traverse(grid, i, j + 1, visited, count, isClosed);
    //     traverse(grid, i - 1, j, visited, count, isClosed);
    //     traverse(grid, i, j - 1, visited, count, isClosed);
    // }
    
    void traverse(vector<vector<int>>& grid, int i, int j, int& count, bool& isClosed) {
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != 1) {
            return;
        }
        grid[i][j] = 2;
        count++;
        if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
            isClosed = false;
        }
        traverse(grid, i + 1, j, count, isClosed);
        traverse(grid, i, j + 1, count, isClosed);
        traverse(grid, i - 1, j, count, isClosed);
        traverse(grid, i, j - 1, count, isClosed);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (n == 1 || m == 1) {
            return 0;
        }
        int res = 0;
        // vector<vector<bool>> visited(n, vector<bool>(m, false));
        // Let's use 2 to denote visited cell in the same grid, to save space complexity
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    bool isClosed = true;
                    traverse(grid, i, j, count, isClosed);
                    if (isClosed) {
                        res += count;
                    }
                }
            }
        }
        // we can change all 2 -> 1 here, to restore the matrix if needed
        return res;
    }
};