class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> isConnected(n , vector<bool>(n, false));

        for (auto& road: roads) {
            int u = road[0], v = road[1];
            isConnected[u][v] = 1;
            isConnected[v][u] = 1;
            degree[u]++;
            degree[v]++;
        }

        int maxRank = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxRank = max(maxRank, degree[i] + degree[j] - isConnected[i][j]);
            }
        }
        return maxRank;
    }
};