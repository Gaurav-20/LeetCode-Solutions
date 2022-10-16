class Solution {
public:
    
    int minDifficulty(vector<int>& jobDifficulty, int days) {
        int n = jobDifficulty.size();
        if (n < days) {
            return -1;
        }
    
        vector<long long> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int d = 1; d <= days; d++) {
            for (int i = 0; i <= n - d; i++) {
                int maxd = 0;
                dp[i] = INT_MAX;
                for (int j = i; j <= n - d; j++) {
                    maxd =  max(maxd, jobDifficulty[j]);
                    dp[i] = min(dp[i], maxd + dp[j + 1]);
                }
            }
        }
        return (int) dp[0];
    }
};