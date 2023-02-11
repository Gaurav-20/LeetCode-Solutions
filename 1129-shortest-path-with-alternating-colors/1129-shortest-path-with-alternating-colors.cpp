#define pii pair<int, int>

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pii>> graph(n);
        for (auto it : redEdges) {
            graph[it[0]].push_back({ it[1], 0 });
        }
        for (auto it : blueEdges) {
            graph[it[0]].push_back({ it[1], 1 });
        }
        vector<int> res(n, -1);
        queue<vector<int>> q;
        q.push({ 0, 0, -1 });

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            res[curr[0]] = res[curr[0]] != -1 ? res[curr[0]] : curr[1];

            for (auto &adj : graph[curr[0]]) {
				if (curr[2] != adj.second && adj.first != -1) {
                    q.push({ adj.first, curr[1] + 1, adj.second });
                    adj.first = -1;
                }
            }
        }
        return res;
    }
};