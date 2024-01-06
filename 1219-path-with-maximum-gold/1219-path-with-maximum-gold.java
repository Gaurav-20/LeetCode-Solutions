class Solution {
    public int m;
    public int n;
    
    public int getMaximumGold(int[][] grid) {
        m = grid.length;
        n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    result = Math.max(dfs(grid, visited, i, j), result);
                }
            }
        }
        return result;
    }
    
    public int dfs(int[][] grid, boolean[][] visited, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0 || visited[i][j] == true) {
            return 0;
        }
        visited[i][j] = true;
        int maxValue = 0;
        if (i > 0) {
            maxValue = Math.max(maxValue, dfs(grid, visited, i - 1, j));
        }
        if (j > 0) {
            maxValue = Math.max(maxValue, dfs(grid, visited, i, j - 1));
        }
        if (i < m - 1) {
            maxValue = Math.max(maxValue, dfs(grid, visited, i + 1, j));
        }
        if (j < n - 1) {
            maxValue = Math.max(maxValue, dfs(grid, visited, i, j + 1));
        }
        visited[i][j] = false;
        return grid[i][j] + maxValue;
    }
}