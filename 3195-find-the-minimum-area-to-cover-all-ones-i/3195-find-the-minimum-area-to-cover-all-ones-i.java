class Solution {
    public int minimumArea(int[][] grid) {
        int left = 10001, right = -1, top = 10001, bottom = -1;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    left = Math.min(j, left);
                    right = Math.max(j, right);
                    top = Math.min(i, top);
                    bottom = Math.max(i, bottom);
                }
            }
        }
        return (right - left + 1) * (bottom - top + 1);
    }
}