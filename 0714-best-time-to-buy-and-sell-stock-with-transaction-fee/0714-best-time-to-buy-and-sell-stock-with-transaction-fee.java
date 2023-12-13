class Solution {
    public int maxProfit(int[] prices, int fee) {
        int n = prices.length;
        int[] buys = new int[n];
        int[] sell = new int[n];
        buys[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            buys[i] = Math.max(buys[i - 1], sell[i - 1] - prices[i]);
            sell[i] = Math.max(sell[i - 1], buys[i - 1] + prices[i] - fee);
        }
        return sell[n - 1];
    }
}