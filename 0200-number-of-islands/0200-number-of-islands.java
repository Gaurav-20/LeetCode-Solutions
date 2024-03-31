class Solution {
    public int rows;
    public int cols;
    
    public int numIslands(char[][] grid) {
        if (grid.length == 0 || grid[0].length == 0) {
            return 0;
        }
        rows = grid.length;
        cols = grid[0].length;
        int count = 0;
        boolean[][] visited = new boolean[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (visited[i][j] == false && grid[i][j] == '1') {
                    count += 1;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return count;
    }
    
    public void dfs(char[][] grid, int i, int j, boolean[][] visited) {
        if (i < 0 || j < 0 || i >= rows || j >= cols || visited[i][j] == true || grid[i][j] == '0') {
            return;
        }
        visited[i][j] = true;
        dfs(grid, i + 1, j, visited);
        dfs(grid, i, j + 1, visited);
        dfs(grid, i - 1, j, visited);
        dfs(grid, i, j - 1, visited);
    }
}