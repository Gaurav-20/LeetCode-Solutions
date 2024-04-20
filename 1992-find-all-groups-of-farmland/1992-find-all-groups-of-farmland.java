class Solution {
    public int[][] findFarmland(int[][] land) {
        int m = land.length;
        int n = land[0].length;
        List<int[]> result = new ArrayList<>();
        for (int row1 = 0; row1 < m; row1++) {
            for (int col1 = 0; col1 < n; col1++) {
                if (land[row1][col1] == 1) {
                    int row2 = row1, col2 = col1;
                    for (row2 = row1; row2 < m && land[row2][col1] == 1; row2++) {
                        for (col2 = col1; col2 < n && land[row2][col2] == 1; col2++) {
                            land[row2][col2] = 0;
                        }
                    }
                    int[] arr = new int[]{ row1, col1, row2 - 1, col2 - 1 };
                    result.add(arr);
                }
            }
        }
        return result.stream().toArray(int[][]::new);
    }
}