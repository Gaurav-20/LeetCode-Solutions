class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for (auto it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        unordered_map<int, bool> mp;
        for (int r : restricted) {
            mp[r] = true;
        }
        vector<bool> visited(n, false);
        int res = 0;
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (!mp[curr]) {
                res++;
            }
            for (auto it : graph[curr]) {
                if (!visited[it] && !mp[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        return res;
    }
};