class Solution {
    
    public int[] dirs = new int[]{ 0, 1, 0, -1, 0 }; 
    public int m;
    public int n;
    
    public boolean exist(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && board[i][j] == word.charAt(0)) {
                    if (solve(board, visited, i, j, 1, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    public boolean solve(char[][] board, boolean[][] visited, int x, int y, int it, String word) {
        visited[x][y] = true;
        if (it == word.length()) {
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dirs[i], ny = y + dirs[i + 1];
            if (isValid(visited, nx, ny) && board[nx][ny] == word.charAt(it)) {
                if (solve(board, visited, nx, ny, it + 1, word)) {
                    return true;
                }
            }
        }
        visited[x][y] = false;
        return false;
    }
    
    public boolean isValid(boolean[][] visited, int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n && !visited[x][y];
    }
}