class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        boolean[][] visited = new boolean[m][n];
        int fresh = 0, result = 0;
        Queue<int[]> queue = new LinkedList<>();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    queue.offer(new int[]{ 0, i, j });
                    visited[i][j] = true;
                } else {
                    visited[i][j] = true;
                }
            }
        }
        
        int[] dirs = new int[]{ 0, 1, 0, -1, 0 };
        
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int time = curr[0], x = curr[1], y = curr[2];
            result = Math.max(result, time);
            for (int i = 0; i < 4; i++) {
                int row = x + dirs[i], col = y + dirs[i + 1];
                if (row < 0 || col < 0 || row >= m || col >= n || visited[row][col] == true) {
                    continue;
                }
                fresh--;
                queue.offer(new int[]{ time + 1, row, col });
                visited[row][col] = true;
            }
        }
        return (fresh == 0) ? result : -1;
    }
}