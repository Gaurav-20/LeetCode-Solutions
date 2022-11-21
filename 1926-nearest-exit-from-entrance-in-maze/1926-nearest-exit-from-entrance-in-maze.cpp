vector<int> dirs = { 0, 1, 0, -1, 0 };

struct Point {
    int xc;
    int yc;
    int dist;
};

class Solution {
public:
    int n, m;
    
    bool isValid(vector<vector<char>>& maze, vector<vector<bool>>& visited, int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] && maze[x][y] == '.';
    }
    
    bool isEdge(vector<int>& entrance, int x, int y) {
        return (x != entrance[0] || y != entrance[1]) && (x == 0 || x == n - 1 || y == 0 || y == m - 1);
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        n = maze.size(), m = maze[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<Point> q;
        q.push({ entrance[0], entrance[1], 0 });
        visited[entrance[0]][entrance[1]] = true;
        while (!q.empty()) {
            int xc = q.front().xc;
            int yc = q.front().yc;
            int dist = q.front().dist;
            q.pop();
            if (isEdge(entrance, xc, yc)) {
                return dist;
            }
            for (int i = 0; i < 4; i++) {
                int nx = xc + dirs[i];
                int ny = yc + dirs[i + 1];
                if (isValid(maze, visited, nx, ny)) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny, dist + 1 });
                }
            }
        }
        return -1;
    }
};