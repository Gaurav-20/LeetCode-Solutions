class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        for (int r : restricted) {
            visited[r] = true;
        }
        int res = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            res++;
            for (auto it : graph[curr]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return res;
    }
};