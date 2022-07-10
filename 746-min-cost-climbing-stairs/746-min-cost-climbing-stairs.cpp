class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        vector<int> minCost(len, 0);
        minCost[len - 1] = cost[len - 1];
        minCost[len - 2] = cost[len - 2];
        
        for (int i = len - 3; i >= 0; i--) {
            minCost[i] = cost[i] + min(minCost[i + 1], minCost[i + 2]);
        }
            
        return min(minCost[0], minCost[1]);
    }
};