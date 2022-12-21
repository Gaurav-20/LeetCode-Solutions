class Solution {
public:
    
    bool checkBipartite(vector<vector<int>>& graph, int node, int parent, vector<int>& color) {
        if (color[node] == -1) {
            color[node] = 1;
        }
        for (auto it : graph[node]) {
            if (color[it] == -1) {
                color[it] = 1 - color[node];
                if (!checkBipartite(graph, it, node, color))
                    return false;
            } else if (color[it] == color[node]) {
                return false;
            }
        }
        return true;
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        for (auto edge : dislikes) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (!checkBipartite(graph, i, -1, color))
                return false;
        }
        return true;
    }
};