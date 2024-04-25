class Solution {
    public int n;
    public int k;
    
    public int longestIdealString(String s, int k) {
        this.n = s.length();
        this.k = k;
        int[][] dp = new int[n + 1][27];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dp[i], -1);
        }
        return solve(s, 0, ' ', dp);
    }
    
    public int solve(String s, int idx, char prev, int[][] dp) {
        if (idx >= n) {
            return 0;
        }
        int prevIdx = (prev == ' ') ? 26 : prev - 'a';
        if (dp[idx][prevIdx] != -1) {
            return dp[idx][prevIdx];
        }
        char curr = s.charAt(idx);
        int maxVal1 = 0, maxVal2 = 0;
        if (prev == ' ' || Math.abs(curr - prev) <= k) {
            maxVal1 = Math.max(1 + solve(s, idx + 1, curr, dp), solve(s, idx + 1, prev, dp));
        } else {
            maxVal2 = solve(s, idx + 1, prev, dp);
        }
        return dp[idx][prevIdx] = Math.max(maxVal1, maxVal2);
    }
}