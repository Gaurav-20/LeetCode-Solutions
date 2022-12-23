int dp[5001][2];

int solve(vector<int>& prices, int index, int n, bool buy) {
    if (index >= n) {
        return 0;
    }
    if (dp[index][buy] != -1) {
        return dp[index][buy];
    }
    int dontBuyDontSell = solve(prices, index + 1, n, buy);
    int buyOrSell = 0;
    if (buy) {
        buyOrSell = -prices[index] + solve(prices, index + 1, n, !buy);
    } else {
        buyOrSell = prices[index] + solve(prices, index + 2, n, !buy);
    }
    return dp[index][buy] = max(dontBuyDontSell, buyOrSell);
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        bool buy = true; // Since we need to buy first
        return solve(prices, 0, prices.size(), buy);
    }
};