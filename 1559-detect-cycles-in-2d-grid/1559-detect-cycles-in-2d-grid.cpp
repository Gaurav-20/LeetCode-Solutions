vector<int> dirs = { 0, -1, 0, 1, 0 };

class Solution {
public:
    int rows, cols;
    
    bool isCyclic(vector<vector<char>>& grid, vector<vector<bool>>& visited, 
                  int row, int col, int prevRow, int prevCol) {
        visited[row][col] = true;
        for (int d = 0; d < 4; d++) {
            int nextRow = row + dirs[d];
            int nextCol = col + dirs[d + 1];
            if (nextRow >= 0 && nextRow < rows 
                && nextCol >= 0 && nextCol < cols
                && grid[nextRow][nextCol] == grid[row][col]
                && !(prevRow == nextRow && prevCol == nextCol)) {
                if (visited[nextRow][nextCol] 
                    || isCyclic(grid, visited, nextRow, nextCol, row, col)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (!visited[row][col] && isCyclic(grid, visited, row, col, -1, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};