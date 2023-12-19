class Solution {
    public int m;
    public int n;
    
    public int[][] imageSmoother(int[][] img) {
        this.m = img.length;
        this.n = img[0].length;
        int[][] result = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = smoothen(img, i, j);
            }
        }
        return result;
    }
    
    public int smoothen(int[][] img, int x, int y) {
        int numCells = 1, sumValues = img[x][y];
        int[] dirX = new int[]{ -1, -1, -1, 0, 0, 1, 1, 1 };
        int[] dirY = new int[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
        for (int i = 0; i < 8; i++) {
            int nx = x + dirX[i], ny = y + dirY[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                sumValues += img[nx][ny];
                numCells++;
            }
        }
        return sumValues / numCells;
    }
}