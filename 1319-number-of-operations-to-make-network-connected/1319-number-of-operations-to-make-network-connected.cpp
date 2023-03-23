class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
        for (auto it : graph[node]) {
            if (!visited[it]) {
                visited[it] = true;
                dfs(graph, it, visited);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for (auto it : connections) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int numCables = connections.size(), numComponents = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                numComponents++;
                dfs(graph, i, visited);
            }
        }
        if (numCables < n - 1 || numCables < numComponents) {
            return -1;
        }
        return numComponents - 1;
    }
};