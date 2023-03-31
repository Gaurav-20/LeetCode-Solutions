#define ll long long
ll MOD = 1e9 + 7;

class Solution {
public:
    int n, m;
    vector<string> pizza;
    ll pre[55][55];
    ll dp[55][55][15];
    
    ll solve(int r, int c, int rest) {
        if (dp[r][c][rest] != -1) {
            return dp[r][c][rest];
        }
        if (rest == 0) {
            if (pre[r][c] > 0) {
                dp[r][c][rest] = 1;
            } else {
                dp[r][c][rest] = 0;
            }
            return dp[r][c][rest];
        }
        dp[r][c][rest] = 0;
        for (int i = r + 1; i < n; i++) {
            if (pre[r][c] - pre[i][c] > 0 && pre[i][c] >= rest) {
                dp[r][c][rest] = (dp[r][c][rest] + solve(i, c, rest - 1)) % MOD;
            }
        }
        for (int j = c + 1; j < m; j++) {
            if (pre[r][c] - pre[r][j] > 0 && pre[r][j] >= rest) {
                dp[r][c][rest] = (dp[r][c][rest] + solve(r, j, rest - 1)) % MOD;
            }
        }
        return dp[r][c][rest];
    }

    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        this->pizza = pizza;
        memset(pre, 0, sizeof(pre));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                pre[i][j] = pre[i][j + 1];
                for (int l = i; l < n; l++) {
                    pre[i][j] += (pizza[l][j] == 'A');
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k - 1);
    }
};