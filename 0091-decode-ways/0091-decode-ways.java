class Solution {
    public int numDecodings(String s) {
        int n = s.length();
        if (n <= 0) {
            return 0;
        }
        int[] dp = new int[n + 1];
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            char ch = s.charAt(i);
            if (ch == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i < n - 1 && (ch == '1' || ch == '2' && s.charAt(i + 1) <= '6')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
}