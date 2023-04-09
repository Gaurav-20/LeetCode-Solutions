typedef long long ll;

class Solution {
public:
    long long solve(int row, int col, map<pair<int, int>, ll>& mp, vector<vector<ll>>& dp) {
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        ll res = mp[{ row, col }];
        for (int i = 1; i <= row / 2; i++) {
            res = max(res, solve(i, col, mp, dp) + solve(row - i, col, mp, dp));
        }
        for (int i = 1; i <= col / 2; i++) {
            res = max(res, solve(row, i, mp, dp) + solve(row, col - i, mp, dp));
        }
        return dp[row][col] = res;
    }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        map<pair<int, int>, ll> mp;
        for (auto it : prices) {
            mp[{ it[0], it[1] }] = it[2];
        }
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -1LL));
        return solve(m, n, mp, dp);
    }
};