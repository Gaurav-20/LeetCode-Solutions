class Solution {
    public int minHeightShelves(int[][] books, int shelfWidth) {
        int n = books.length;
        Integer[] dp = new Integer[n];
        return solve(books, n, shelfWidth, 0, dp);
    }
    
    public int solve(int[][] books, int n, int shelfWidth, int i, Integer[] dp) {
        if (i == n) {
            return 0;
        }
        if (dp[i] != null) {
            return dp[i];
        }
        int result = Integer.MAX_VALUE, maxHeight = 0, width = 0;
        for (int j = i; j < n; j++) {
            width = width + books[j][0];
            if (width > shelfWidth) {
                break;
            }
            maxHeight = Math.max(maxHeight, books[j][1]);
            result = Math.min(result, maxHeight + solve(books, n, shelfWidth, j + 1, dp));
        }
        return dp[i] = result;
    }
}