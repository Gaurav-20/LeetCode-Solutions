typedef long long ll;

class Solution {
public:
    // long long rec(int row, int col, map<pair<int, int>, ll>& mp, vector<vector<ll>>& dp) {
    //     if (dp[row][col] != -1) {
    //         return dp[row][col];
    //     }
    //     ll res = mp[{ row, col }];
    //     for (int i = 1; i <= row / 2; i++) {
    //         res = max(res, rec(i, col, mp, dp) + rec(row - i, col, mp, dp));
    //     }
    //     for (int i = 1; i <= col / 2; i++) {
    //         res = max(res, rec(row, i, mp, dp) + rec(row, col - i, mp, dp));
    //     }
    //     return dp[row][col] = res;
    // }
    
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        // map<pair<int, int>, ll> mp;
        // vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, -1LL));
        vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0LL)); // handle base case by zero init
        for (auto it : prices) {
            // mp[{ it[0], it[1] }] = it[2];
            // space optimization, store mp in dp array itself
            dp[it[0]][it[1]] = it[2];
        }
        // return rec(m, n, mp, dp);
        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {
                // ll res = mp[{ row, col }];
                ll res = dp[row][col];
                for (int i = 1; i <= row / 2; i++) {
                    res = max(res, dp[i][col] + dp[row - i][col]);
                }
                for (int i = 1; i <= col / 2; i++) {
                    res = max(res, dp[row][i] + dp[row][col - i]);
                }
                dp[row][col] = res;
            }
        }
        return dp[m][n];
    }
};