class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int color = 0;
                if (grid[i][j] == 'W') {
                    color += 1;
                }
                if (grid[i + 1][j] == 'W') {
                    color += 1;
                }
                if (grid[i + 1][j + 1] == 'W') {
                    color += 1;
                }
                if (grid[i][j + 1] == 'W') {
                    color += 1;
                }
                if (color != 2) {
                    return true;
                }
            }
        }
        return false;
    }
}