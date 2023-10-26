class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int>(2, -1));
        // dp[0][0] = 0;
        // dp[0][1] = nums[0];
        int prevNotTaken = 0;
        int prevTaken = nums[0];
        int currNotTaken = 0;
        int currTaken = nums[0];
        for (int i = 1; i < n; i++) {
            // dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            // dp[i][1] = dp[i - 1][0] + nums[i];
            currNotTaken = max(prevTaken, prevNotTaken);
            currTaken = prevNotTaken + nums[i];
            prevNotTaken = currNotTaken;
            prevTaken = currTaken;
        }
        // return max(dp[n - 1][0], dp[n - 1][1]);
        return max(currTaken, currNotTaken);
    }
};