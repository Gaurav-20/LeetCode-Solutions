class Solution {
    public boolean canMakeSquare(char[][] grid) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int whites = 0, blacks = 0;
                if (grid[i][j] == 'W') {
                    whites += 1;
                } else {
                    blacks += 1;
                }
                if (grid[i + 1][j] == 'W') {
                    whites += 1;
                } else {
                    blacks += 1;
                }
                if (grid[i + 1][j + 1] == 'W') {
                    whites += 1;
                } else {
                    blacks += 1;
                }
                if (grid[i][j + 1] == 'W') {
                    whites += 1;
                } else {
                    blacks += 1;
                }
                if (whites >= 3 || blacks >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
}