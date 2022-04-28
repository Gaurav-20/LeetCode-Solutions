struct node {
    int dist;
    int row;
    int col;
};

bool operator < (const node& n1, const node& n2) {
    return n1.dist < n2.dist;
}

vector<int> dir = { 0, 1, 0, -1, 0 };

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        priority_queue<node> pq;
        pq.push({ 0, 0, 0 });
        while (!pq.empty()) {
            node elem = pq.top();
            pq.pop();
            int d = -elem.dist, r = elem.row, c = elem.col;
            if (d > distance[r][c]) {
                continue;
            }
            if (r == n - 1 && c == m - 1) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i], nc = c + dir[i + 1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newDist = max(d, abs(heights[nr][nc] - heights[r][c]));
                    if (distance[nr][nc] > newDist) {
                        distance[nr][nc] = newDist;
                        pq.push({ -distance[nr][nc], nr, nc });
                    }
                }
            }
        }
        return -1;
    }
};