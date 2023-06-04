class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, int node, vector<int>& visited) {
        visited[node] = 1;
        for (int i = 0; i < n; i++) {
            if (isConnected[i][node] == 1 && !visited[i]) {
                dfs(isConnected, n, i, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, n, i, visited);
            }
        }
        return provinces;
    }
};