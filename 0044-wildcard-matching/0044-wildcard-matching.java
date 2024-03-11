class Solution {
    public int[][] dp;
    
    public boolean isMatch(String str, String pattern) {
        dp = new int[pattern.length()][str.length()];
        for (int i = 0; i < pattern.length(); i++) {
            Arrays.fill(dp[i], -1);
        }
        return (solve(pattern, str, pattern.length() - 1, str.length() - 1) == 1);
    }
    
    public int solve(String pattern, String str, int i, int j) {
        if (i < 0 && j < 0) {
            return 1;
        }
        if (i < 0 && j >= 0) {
            return 0;
        }
        if (j < 0 && i >= 0) {
            for (int k = 0; k <= i; k++) {
                if (pattern.charAt(k) != '*') {
                    return 0;
                }
            }
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        if (pattern.charAt(i) == str.charAt(j) || pattern.charAt(i) == '?') {
            return dp[i][j] = solve(pattern, str, i - 1, j - 1);
        }
        if (pattern.charAt(i) == '*') {
            int case1 = solve(pattern, str, i - 1, j);
            int case2 = solve(pattern, str, i, j - 1);
            return dp[i][j] = ((case1 == 1) || (case2 == 1)) ? 1 : 0;
        }
        return dp[i][j] = 0;
    }
}