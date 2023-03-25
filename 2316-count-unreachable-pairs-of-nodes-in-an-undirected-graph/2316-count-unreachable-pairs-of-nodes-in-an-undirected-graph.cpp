class Solution {
public:
    void dfs(vector<vector<int>>& graph, int root, vector<bool>& visited, int& count) {
        visited[root] = true;
        count++;
        for (auto node : graph[root]) {
            if (!visited[node]) {
                dfs(graph, node, visited, count);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n);
        vector<int> componentSizes;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int size = 0;
                dfs(graph, i, visited, size);
                componentSizes.push_back(size);
            }
        }
        long long res = 0;
        for (int curr : componentSizes) {
            long long rest = n - curr;
            res += curr * rest;
        }
        return res / 2;
    }
};