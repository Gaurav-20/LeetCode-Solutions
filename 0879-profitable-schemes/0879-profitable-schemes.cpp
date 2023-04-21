typedef long long ll;
const ll MOD = 1e9 + 7;

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<ll>> dp(n + 1, vector<ll>(minProfit + 1, 0));
        dp[0][0] = 1;
        for (ll it = 1; it <= group.size(); it++) {
            ll p = profit[it - 1];
            ll g = group[it - 1];
            for (int i = n; i >= g; i--) {
                for (int j = minProfit; j >= 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - g][max(0LL, j - p)]) % MOD;
                }
            }
        }
        ll res = 0;
        for (ll i = 0; i <= n; i++) {
            res = (res + dp[i][minProfit]) % MOD;
        }
        return res;
    }
};