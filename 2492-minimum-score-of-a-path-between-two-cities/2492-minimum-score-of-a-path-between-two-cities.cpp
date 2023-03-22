#define pii pair<long long, int>

class Solution {
public:
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pii> adj[n + 1];
        for (auto road : roads) {
            adj[road[0]].push_back({ road[2], road[1] });
            adj[road[1]].push_back({ road[2], road[0] });
        }
        long long res = INT_MAX;
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;
            for (auto it : adj[node]) {
                if (!visited[it.second]) {
                    res = min(res, it.first);
                    q.push(it.second);
                }
            }
        }
        return res;
    }
};