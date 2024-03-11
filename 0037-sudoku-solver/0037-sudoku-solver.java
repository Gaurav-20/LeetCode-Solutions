class Solution {
    public static int N = 9;
    
    public void solveSudoku(char[][] board) {
        solve(board, 0, 0);
    }
    
    public boolean solve(char[][] board, int row, int col) {
        if (row == N - 1 && col == N) {
            return true;
        }
        if (col == N) {
            row += 1;
            col = 0;
        }
        if (board[row][col] != '.') {
            return solve(board, row, col + 1);
        }
        for (int i = 1; i <= N; i++) {
            char curr = (char) (i + '0');
            if (canPlaceNumber(board, row, col, curr)) {
                board[row][col] = curr;
                if (solve(board, row, col + 1)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    public boolean canPlaceNumber(char[][] board, int x, int y, char num) {
        for (int i = 0; i < N; i++) {
            if (board[x][i] == num) {
                return false;
            }
            if (board[i][y] == num) {
                return false;
            }
        }
        int xGrid = x / 3 * 3, yGrid = y / 3 * 3;
        for (int i = xGrid; i < xGrid + 3; i++) {
            for (int j = yGrid; j < yGrid + 3; j++) {
                if (board[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
    }
}