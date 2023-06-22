class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) {
            return 0;
        }
        int days = n; 
        vector<int> buy(n), sell(n);
        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]); 
            // keep the same as day i-1, or buy from sell status at day i-1
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee); 
            // keep the same as day i-1, or sell from buy status at day i-1
        }
        return sell.back();
    }
};