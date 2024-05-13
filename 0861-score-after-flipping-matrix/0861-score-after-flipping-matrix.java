class Solution {
    public int matrixScore(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int ones = 0, zeros = 0;
            for (int i = 0; i < m; i++) {
                ones += (grid[i][j] == 1) ? 1 : 0;
                zeros += (grid[i][j] == 0) ? 1 : 0;
            }
            if (ones < zeros) {
                for (int i = 0; i < m; i++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        int result = 0;
        for (int[] row : grid) {
            result += getBinaryValue(row);
        }
        return result;
    }
    
    public int getBinaryValue(int[] row) {
        int bin = 0;
        for (int i = 0; i < row.length; i++) {
            bin = (bin * 2) + row[i];
        }
        return bin;
    }
}