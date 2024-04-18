class Solution {
    public int rows;
    public int cols;
    
    public int islandPerimeter(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        int perimeter = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += findSurroundingWaterLength(grid, i, j);
                }
            }
        }
        return perimeter;
    }
    
    public int findSurroundingWaterLength(int[][] grid, int x, int y) {
        int water = 4;
        if (x + 1 < rows && grid[x + 1][y] == 1) {
            water -= 1;
        }
        if (y + 1 < cols && grid[x][y + 1] == 1) {
            water -= 1;
        }
        if (x - 1 >= 0 && grid[x - 1][y] == 1) {
            water -= 1;
        }
        if (y - 1 >= 0 && grid[x][y - 1] == 1) {
            water -= 1;
        }
        return water;
    }
}