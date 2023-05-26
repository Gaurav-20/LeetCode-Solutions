class Solution {
public:
    int solve(vector<int>& piles, vector<vector<int>>& dp, vector<int>& suffixSum, int n, int i, int M) {
        if (i >= n) {
            return 0;
        }
        if (i + 2 * M >= n) {
            return suffixSum[i];
        }
        if (dp[i][M] != -1) {
            return dp[i][M];
        }
        int res = 0;
        for (int x = 1; x <= 2 * M; x++) {
            res = max(res, suffixSum[i] - solve(piles, dp, suffixSum, n, i + x, max(x, M)));
        }
        return dp[i][M] = res;
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] += suffixSum[i + 1] + piles[i];
        }
        return solve(piles, dp, suffixSum, n, 0, 1); // i = 0 and M = 1 initially
    }
};