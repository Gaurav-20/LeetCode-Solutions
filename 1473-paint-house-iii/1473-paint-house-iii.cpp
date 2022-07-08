#define INF 1000001

class Solution {
public:
    int dp[101][101][21];
    int dfs(vector<int>& houses, vector<vector<int>>& cost, int i, int target, int lastColor) {
        if (i >= houses.size() || target < 0) {
            return target == 0 ? target : 1000001;
        }
        if (houses[i] != 0) {
            return dfs(houses, cost, i + 1, target - (lastColor != houses[i]), houses[i]);      
        }
        if (dp[i][target][lastColor]) {
            return dp[i][target][lastColor];
        }
        int res = INF;
        for (auto color = 1; color <= cost[i].size(); color++) {
            res = min(res, cost[i][color - 1] + 
                      dfs(houses, cost, i + 1, target - (lastColor != color), color));
        }            
        return dp[i][target][lastColor] = res;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int res = dfs(houses, cost, 0, target, 0);
        return (res >= INF) ? -1 : res;
    }
};