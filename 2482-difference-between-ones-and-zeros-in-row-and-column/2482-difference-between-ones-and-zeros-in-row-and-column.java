class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[] onesRow = new int[m]; // zerosRow[i] = n - onesRow[i]
        int[] onesCol = new int[n]; // zerosCol[i] = m - onesCol[i]
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    onesRow[i] += 1;
                    onesCol[j] += 1;
                }
            }
        }
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // result[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
                // result[i][j] = onesRow[i] + onesCol[j] - (n - onesRow[i]) - (m - onesCol[j]);
                result[i][j] = (2 * onesRow[i] + 2 * onesCol[j]) - n - m;
            }
        }
        return result;
    }
}