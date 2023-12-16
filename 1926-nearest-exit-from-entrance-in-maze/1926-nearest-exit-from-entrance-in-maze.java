class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int m = maze.length, n = maze[0].length;
        boolean[][] visited = new boolean[m][n];
        visited[entrance[0]][entrance[1]] = true;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{ entrance[0], entrance[1], 0 });
        while (!queue.isEmpty()) {
            int[] curr = queue.poll();
            int x = curr[0], y = curr[1], steps = curr[2];
            if (maze[x][y] == '+') {
                continue;
            }
            if ((x != entrance[0] || y != entrance[1]) && (x == 0 || x == m - 1 || y == 0 ||  y == n - 1)) {
                return steps;
            }
            if (x > 0 && visited[x - 1][y] == false) {
                queue.offer(new int[]{ x - 1, y, steps + 1 });
                visited[x - 1][y] = true;
            }
            if (y > 0 && visited[x][y - 1] == false) {
                queue.offer(new int[]{ x, y - 1, steps + 1 });
                visited[x][y - 1] = true;
            }
            if (x < m - 1 && visited[x + 1][y] == false) {
                queue.offer(new int[]{ x + 1, y, steps + 1 });
                visited[x + 1][y] = true;
            }
            if (y < n - 1 && visited[x][y + 1] == false) {
                queue.offer(new int[]{ x, y + 1, steps + 1 });
                visited[x][y + 1] = true;
            }
        }
        return -1;
    }
}