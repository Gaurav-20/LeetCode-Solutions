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
    bool isValidCell(vector<vector<int>>& grid, int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n && (grid[x][y] == 0);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        queue<Cell> q;
        q.push({ 0, 0, 1 });
        grid[0][0] = -1; // visited is -1
        while (!q.empty()) {
            Cell curr = q.front();
            q.pop();
            if (curr.xCoordinate == n - 1 && curr.yCoordinate == n - 1) {
                return curr.distance;
            }
            for (int i = 0; i < 8; i++) {
                int nextXCoordinate = curr.xCoordinate + directions[i][0];
                int nextYCoordinate = curr.yCoordinate + directions[i][1];
                if (isValidCell(grid, nextXCoordinate, nextYCoordinate, n)) {
                    grid[nextXCoordinate][nextYCoordinate] = -1;
                    q.push({ nextXCoordinate, nextYCoordinate, curr.distance + 1 });
                }
            }
        }
        return -1;
    }
};