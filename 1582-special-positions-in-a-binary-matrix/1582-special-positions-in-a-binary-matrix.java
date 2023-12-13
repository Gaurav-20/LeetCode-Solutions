class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        // if rows[i] is k, it means there are k 1's in the row and same logic for cols[i]
        int[] rows = new int[m];
        int[] cols = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        int countOfSpecialPositions = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) {
                    countOfSpecialPositions++;
                }
            }
        }
        return countOfSpecialPositions;
    }
}