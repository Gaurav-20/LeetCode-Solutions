int dirX[4] = { 0, 0, 1, -1 };
int dirY[4] = { 1, -1, 0, 0 };

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int countIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    countIslands++;
                    queue<pair<int, int>> q;
                    q.push({ i, j });
                    visited[i][j] = true;
                    while (!q.empty()) {
                        int qx = q.front().first;
                        int qy = q.front().second;
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nx = qx + dirX[d];
                            int ny = qy + dirY[d];
                            if (nx >= 0 && ny >= 0 && nx < rows && ny < cols 
                                && grid[nx][ny] == '1' && !visited[nx][ny]) {
                                q.push({nx, ny});
                                visited[nx][ny] = true;

                            }
                        }
                    }
                }
            }
        }
        return countIslands;
    }
};