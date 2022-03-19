int dp[1001][101][2];

int solve(vector<int>& prices, int index, int n, int k, bool buy) {
    if (index >= n || k <= 0) {
        return 0;
    }
    if (dp[index][k][buy] != -1) {
        return dp[index][k][buy];
    }
    int dontBuyDontSell = solve(prices, index + 1, n, k, buy);
    int buyOrSell = 0;
    if (buy) {
        buyOrSell = -prices[index] + solve(prices, index + 1, n, k, !buy);
    } else {
        buyOrSell = prices[index] + solve(prices, index + 1, n, k - 1, !buy);
    }
    return dp[index][k][buy] = max(dontBuyDontSell, buyOrSell);
}

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, prices.size(), k, true);
    }
};