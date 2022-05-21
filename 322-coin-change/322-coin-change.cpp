class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, (int)1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
            for (int x : coins) {
                if (i >= x) {
                    dp[i] = min(1 + dp[i - x], dp[i]);
                }
            }
        }
        return (dp[amount] == 1e9) ? -1 : dp[amount];
    }
};