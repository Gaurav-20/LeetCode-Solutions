int dp[30001][2];

int solve(vector<int>& prices, int index, int n, bool hold) {
    if (index >= n) {
        return 0;
    }
    if (dp[index][hold] != -1) {
        return dp[index][hold];
    }
    int dontBuyDontSell = solve(prices, index + 1, n, hold);
    int buyOrSell = 0;
    if (!hold) {
        buyOrSell = -prices[index] + solve(prices, index + 1, n, !hold);
    } else {
        buyOrSell = prices[index] + solve(prices, index + 1, n, !hold);
    }
    return dp[index][hold] = max(dontBuyDontSell, buyOrSell);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        bool hold = false; // Initially there are no holdings
        return solve(prices, 0, prices.size(), hold);
    }
};