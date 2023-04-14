class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // The idea is to find the longest common subsequence of s & its reverse
        string str = s;
        reverse(str.begin(), str.end());
        int n = s.size();
        // Space optimised version of lcs
        vector<vector<int>> dp(2, vector<int>(n + 1, 0));
        int bi = 0;
        
        for (int i = 0; i <= n; i++) {
            bi = i & 1;
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    dp[bi][j] = 0;
                } else if (str[i - 1] == s[j - 1]) {
                    dp[bi][j] = 1 + dp[1 - bi][j - 1];
                } else {
                    dp[bi][j] = max(dp[1 - bi][j], dp[bi][j - 1]);
                }
            }
        }
        return dp[bi][n];
    }
};