class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (n >= k + maxPts - 1) {
            return 1.0;
        }
        
        double prob = 1.0 / maxPts; // Probability of each score
        double prev = 0.0;
        
        vector<double> dp(n + maxPts);
        dp[0] = 1.0;
        
        for (int i = 1; i <= k; i++) {
            prev = prev - ((i > maxPts) ? dp[i - maxPts - 1] : 0.0) + dp[i - 1];
            dp[i] = prev * prob;
        }
        
        double res = dp[k];
        
        for (int i = k + 1; i <= n; i++) {
            prev = prev - ((i > maxPts) ? dp[i - maxPts - 1] : 0.0);
            dp[i] = prev * prob;
            res += dp[i];
        }
        
        return res;
    }
};