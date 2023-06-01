struct Cell {
    int xCoordinate;
    int yCoordinate;
    int distance;
};

vector<vector<int>> directions = {
    { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }
};

class Solution {
public:
    int n;
    
    bool isValidCell(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n && (grid[x][y] == 0) && !visited[x][y];
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) {
            return -1;
        }
        n = grid.size();
        queue<Cell> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        q.push({ 0, 0, 1 });
        visited[0][0] = true;
        while (!q.empty()) {
            Cell curr = q.front();
            q.pop();
            if (curr.xCoordinate == n - 1 && curr.yCoordinate == n - 1) {
                return curr.distance;
            }
            for (auto dir: directions) {
                int nextXCoordinate = curr.xCoordinate + dir[0];
                int nextYCoordinate = curr.yCoordinate + dir[1];
                if (isValidCell(grid, visited, nextXCoordinate, nextYCoordinate)) {
                    visited[nextXCoordinate][nextYCoordinate] = true;
                    q.push({ nextXCoordinate, nextYCoordinate, curr.distance + 1 });
                }
            }
        }
        return -1;
    }
};