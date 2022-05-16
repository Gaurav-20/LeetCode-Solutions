struct Node {
    int x;
    int y;
    int d;
};

bool visited[101][101];

bool isValid(vector<vector<int>>& grid, int x, int y, int n) {
    return x >= 0 && y >= 0 && x < n && y < n && !visited[x][y] && grid[x][y] == 0;
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        queue<Node> q;
        q.push({ 0, 0, 1 });
        visited[0][0] = true;
        while (!q.empty()) {
            Node node = q.front();
            q.pop();
            if (node.x == n - 1 && node.y == n - 1) {
                return node.d;
            }
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    int nextX = node.x + i;
                    int nextY = node.y + j;
                    if (isValid(grid, nextX, nextY, n)) {
                        visited[nextX][nextY] = true;
                        q.push({ nextX, nextY, node.d + 1 });
                    }
                }
            }
        }
        return -1;
    }
};