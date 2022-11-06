const long long MAX = 1e18;

class Solution {
public:
    long long solve(int i, int j, vector<int>& robot, vector<int>& factories, 
                    vector<vector<long long>>& dp) {
        if (i == robot.size()) {
            // all robots done
            return 0;
        }
        if (j == factories.size()) {
            // all factories exhausted so can't repair
            return MAX;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long long choose = abs(robot[i] - factories[j]) + solve(i + 1, j + 1, robot, factories, dp);
        long long notChoose = solve(i, j + 1, robot, factories, dp);
        return dp[i][j] = min(choose, notChoose);
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int> factories;
        // Consolidated factories, if a factory at position x has limit y
        // it is equivalent to having y factories with limit 1 at the same position x
        for (vector<int> fact : factory) {
            int x = fact[0], y = fact[1];
            for (int i = 0; i < y; i++) {
                factories.push_back(x);
            }
        }
        vector<vector<long long>> dp(robot.size() + 1, vector<long long>(factories.size() + 1, -1));
        return solve(0, 0, robot, factories, dp);
    }
};