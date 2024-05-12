class Solution {
    public int[][] largestLocal(int[][] grid) {
        int n = grid.length;
        int[][] result = new int[n - 2][n - 2];
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                result[i][j] = maxVal(grid, i, j);
            }
        }
        return result;
    }
    
    public int maxVal(int[][] grid, int x, int y) {
        int result = -1;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                result = Math.max(result, grid[i][j]);
            }
        }
        return result;
    }
}