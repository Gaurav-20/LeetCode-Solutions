#define pii pair<int, int>

class Solution {
public:
    int manhattanWeight(vector<int>& point1, vector<int>& point2) {
        return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0, i = 0, connected = 0;
        vector<bool> visited(n);
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        while (++connected < n) {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    pq.push({ manhattanWeight(points[i], points[j]), j });
                }
            }
            while (visited[pq.top().second]) {
                pq.pop();
            }
            res += pq.top().first;
            i = pq.top().second;
            pq.pop();
        }
        return res;
    }
};