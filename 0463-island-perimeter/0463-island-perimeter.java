class Solution {
    public int rows;
    public int cols;
    public int perimeter;
    
    public int islandPerimeter(int[][] grid) {
        this.rows = grid.length;
        this.cols = grid[0].length;
        this.perimeter = 0;
        boolean[][] visited = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(grid, i, j, visited);
                }
            }
        }
        return this.perimeter;
    }
    
    public void dfs(int[][] grid, int x, int y, boolean[][] visited) {
        if (x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] || grid[x][y] == 0) {
            return;
        }
        visited[x][y] = true;
        this.perimeter += findSurroundingWaterLength(grid, x, y);
        dfs(grid, x + 1, y, visited);
        dfs(grid, x, y + 1, visited);
        dfs(grid, x - 1, y, visited);
        dfs(grid, x, y - 1, visited);
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