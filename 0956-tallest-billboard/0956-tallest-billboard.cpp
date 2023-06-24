class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;

        for (int rod : rods) {
            vector<int> dpCopy = dp;
            for (int i = 0; i <= sum - rod; i++) {
                if (dpCopy[i] < 0) {
                    continue;
                }
                // Case 1: Place the current rod on the same height billboard
                dp[i + rod] = max(dp[i + rod], dpCopy[i]);
                
                // Case 2: Place the current rod on the taller billboard
                // Calculate the absolute difference between current height and rod length
                dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
            }
        }
        // Return the maximum height of the billboard stored at dp[0]
        return dp[0];
    }
};