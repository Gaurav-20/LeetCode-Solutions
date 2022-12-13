class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0] = matrix[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int temp = dp[i - 1][j];
                if (j > 0) {
                    temp = min(temp, dp[i - 1][j - 1]);
                }
                if (j < n - 1) {
                    temp = min(temp, dp[i - 1][j + 1]);
                }
                dp[i][j] = matrix[i][j] + temp;
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};