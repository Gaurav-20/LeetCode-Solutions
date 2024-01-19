class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        int result = Integer.MAX_VALUE;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int topLeft = matrix[i - 1][Math.max(j - 1, 0)];
                int topRight = matrix[i - 1][Math.min(j + 1, n - 1)];
                int top = matrix[i - 1][j];
                matrix[i][j] += Math.min(top, Math.min(topLeft, topRight));
            }
        }
        for (int j = 0; j < n; j++) {
            result = Math.min(result, matrix[m - 1][j]);
        }
        return result;
    }
}