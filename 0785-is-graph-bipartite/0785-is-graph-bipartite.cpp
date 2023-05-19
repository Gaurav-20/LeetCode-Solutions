class Solution {
public:
    bool checkBipartiteBfs(vector<vector<int>>& graph, int curr, vector<int>& color) {
        queue<int> q;
        q.push(curr);
        color[curr] = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int& it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = 1 - color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int node = 0; node < n; node++) {
            if (color[node] == -1) {
                if (!checkBipartiteBfs(graph, node, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};