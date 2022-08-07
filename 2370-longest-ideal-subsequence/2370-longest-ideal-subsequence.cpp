class Solution {
public:
    int n;
    int dp[50][100005];

    int solve(string &s, int prev, int k, int pos) {
        if (pos >= n) {
            return 0;
        }
        if (dp[prev][pos] != -1) {
            return dp[prev][pos];
        }
        int include = 0, exclude = 0;
        if (prev == 26 || abs(prev - s[pos] + 'a') <= k) {
            include = 1 + solve(s, s[pos] - 'a', k, pos + 1);
        }
        exclude = solve(s, prev, k, pos + 1);
        return dp[prev][pos] = max(include, exclude);
    }

    int longestIdealString(string s, int k) {
        n = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 26, k, 0);
    }
};