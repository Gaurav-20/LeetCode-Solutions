int dp[400];

class Solution {
public:
    int solve(vector<bool>& trips, vector<int>& costs, int day) {
        if (day >= trips.size()) {
            return 0;
        }
        if (dp[day] != -1) {
            return dp[day];
        }
        if (!trips[day]) {
            return dp[day] = solve(trips, costs, day + 1);
        }
        return dp[day] = min({
            costs[0] + solve(trips, costs, day + 1),
            costs[1] + solve(trips, costs, day + 7),
            costs[2] + solve(trips, costs, day + 30)
        });
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        vector<bool> trips(days.back(), false);
        for (int& day : days) {
            trips[day - 1] = true;
        }
        return solve(trips, costs, 0);
    }
};