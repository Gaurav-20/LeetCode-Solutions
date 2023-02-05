class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({ 0, 0 });
        visited[0][0] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            if (x == n - 1 && y == m - 1) {
                return false;
            }
            if (q.size() == 1) {
                if (!(x == 0 && y == 0) && !(x == n - 1 && y == m - 1)) {
                    return true;
                }
            }
            int len = q.size();
            for (int i = 0; i < len; i++) {
                x = q.front().first, y = q.front().second;
                q.pop();
                if (x + 1 < n && grid[x + 1][y] == 1 && !visited[x + 1][y]) {
                    q.push({ x + 1, y });
                    visited[x + 1][y] = true;
                }
                if (y + 1 < m && grid[x][y + 1] == 1 && !visited[x][y + 1]) {
                    q.push({ x, y + 1 });
                    visited[x][y + 1] = true;
                }
            }
        }
        return true;
    }
};