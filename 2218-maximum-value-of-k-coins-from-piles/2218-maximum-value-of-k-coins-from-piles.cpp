class Solution {
public:
    int solve(vector<vector<int>>& piles, vector<vector<int>>& dp, int index, int coins) {
        if (index == piles.size() || coins == 0) {
            return 0;
        }
        if (dp[index][coins] != -1) {
            return dp[index][coins];
        }
        int res = solve(piles, dp, index + 1, coins), curr = 0;
        for (int i = 0; i < piles[index].size() && i < coins; i++) {
            curr += piles[index][i];
            res = max(res, curr + solve(piles, dp, index + 1, coins - i - 1));
        }
        return dp[index][coins] = res;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size() + 1, vector<int>(k + 1, -1));
        return solve(piles, dp, 0, k);
    }
};