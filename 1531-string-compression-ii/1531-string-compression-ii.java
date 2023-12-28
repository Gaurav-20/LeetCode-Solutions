class Solution {
    public int getLengthOfOptimalCompression(String s, int k) {
        int n = s.length();
        int[][] dp = new int[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], 100000);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j > 0) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                int removed = 0, count = 0;
                for (int p = i; p > 0; p--) {
                    if (s.charAt(p - 1) == s.charAt(i - 1)) {
                        count++;
                    } else if (++removed > j) {
                        break;
                    }
                    dp[i][j] = Math.min(dp[i][j], dp[p - 1][j - removed] + findLen(count));
                }
            }
        }
        return dp[n][k];
    }
    
    public int findLen(int n) {
        if (n < 1) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n < 10) {
            return 2;
        } else if (n < 100) {
            return 3;
        } else {
            return 4;
        }
    }
}