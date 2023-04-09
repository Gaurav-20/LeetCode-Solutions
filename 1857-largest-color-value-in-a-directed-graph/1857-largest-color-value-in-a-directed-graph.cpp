class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        queue<int> q; // Kahn's algo
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<vector<int>> counts(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            counts[i][colors[i] - 'a']++;
        }
        int visitedCount = 0, res = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            visitedCount++;
            for (auto v : graph[u]) {
                for (int i = 0; i < 26; i++) {
                    counts[v][i] = max(counts[v][i], counts[u][i] + (colors[v] - 'a' == i));
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
            res = max(res, *max_element(counts[u].begin(), counts[u].end()));
        }
        return (visitedCount == n) ? res : -1; // -1 means cycle
    }
};