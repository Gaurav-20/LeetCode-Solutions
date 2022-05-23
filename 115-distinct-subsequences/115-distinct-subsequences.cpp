int dp[1005][1005];

class Solution {
public:
    int n, m;
    int solve(string& s, string& t, int i, int j) {
        if (j == m) {
            return 1;
        }
        if (i == n) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        long long res = 0;
        for (int ind = i; ind <= min(n - 1, n - m + j); ind++) {
            if (s[ind] == t[j]) {
                res += solve(s, t, ind + 1, j + 1);
            }
        }
        return dp[i][j] = res;
    }
    
    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        n = s.size(), m = t.size();
        return solve(s, t, 0, 0);
    }
};