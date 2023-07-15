class Solution {
public:
    int solve(vector<vector<int>>& events, int k, int i, vector<vector<int>>& dp) {
        if (i >= events.size()) {
            return 0;
        }
        if (dp[i][k] != -1) {
            return dp[i][k];
        }
        int res = solve(events, k, i + 1, dp);
        if (k > 0) {
            vector<int> temp = { events[i][1], INT_MAX, INT_MAX };
           int it = upper_bound(events.begin(), events.end(), temp) - events.begin();
           res = max(res, events[i][2] + solve(events, k - 1, it, dp));
        }
        return dp[i][k] = res;
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return solve(events, k, 0, dp);
    }
};