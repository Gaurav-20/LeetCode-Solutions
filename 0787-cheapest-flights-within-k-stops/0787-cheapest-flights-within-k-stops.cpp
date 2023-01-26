class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Bellman Ford Algorithm
        vector<long long> cost(n, INT_MAX);
        cost[src] = 0;
        
        for (int round = 0; round <= k; round++) {
            vector<long long> updatedCost(cost);
            for (auto it : flights) {
                int start = it[0], end = it[1], startToEndCost = it[2];
                updatedCost[end] = min(updatedCost[end], cost[start] + startToEndCost);
            }
            cost = updatedCost;
        }
        return cost[dst] == INT_MAX ? -1 : cost[dst];
    }
};