class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0LL);
        for (int i = n - 1; i >= 0; i--) {
            long long points = questions[i][0], brainpower = questions[i][1];
            if (i + brainpower + 1 < n) {
                dp[i] = max(dp[i], points + dp[i + brainpower + 1]);
            } else {
                dp[i] = max(dp[i], points);
            }
            if (i + 1 < n) {
                dp[i] = max(dp[i], dp[i + 1]);
            }
        }
        return dp[0];
    }
};