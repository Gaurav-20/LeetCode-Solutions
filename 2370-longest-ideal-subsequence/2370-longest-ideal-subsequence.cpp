class Solution {
public:
    int n;
    int solve(string& s, int idx, int prev, int& k, vector<vector<int>>& dp) {
        if (idx >= n) {
            return 0;
        }
        if (dp[idx][prev] != -1) {
            return dp[idx][prev];
        }
        int include = 0, exclude = 0;
        if (prev == 0 || abs(s[idx] - prev) <= k) {
            include = 1 + solve(s, idx + 1, s[idx], k, dp);
        }
        exclude = solve(s, idx + 1, prev, k, dp);
        return dp[idx][prev] = max(include, exclude);
    }
    
    int longestIdealString(string s, int k) {
        n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(150, -1));
        return solve(s, 0, 0, k, dp);
    }
};