class Solution {
    public boolean isMatch(String str, String pattern) {
        int n = pattern.length(), m = str.length();
        boolean[] curr = new boolean[m + 1];
        boolean[] prev = new boolean[m + 1];
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            boolean flag = true;
            for (int ii = 1; ii <= i; ii++) {
                if (pattern.charAt(ii - 1) != '*') {
                    flag = false;
                }
            }
            curr[0] = flag;
            for (int j = 1; j <= m; j++) {
                if (pattern.charAt(i - 1) == str.charAt(j - 1) || pattern.charAt(i - 1) == '?') {
                    curr[j] = prev[j - 1];
                } else if (pattern.charAt(i - 1) == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr.clone();
        }
        return prev[m];
    }
}