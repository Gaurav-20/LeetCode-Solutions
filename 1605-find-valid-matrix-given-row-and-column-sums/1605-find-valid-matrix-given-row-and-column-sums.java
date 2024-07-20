class Solution {
    public int[][] restoreMatrix(int[] rowSum, int[] colSum) {
        int rows = rowSum.length, cols = colSum.length;
        int[][] result = new int[rows][cols];
        Integer[][] rowWithIndex = new Integer[rows][2];
        Integer[][] colWithIndex = new Integer[cols][2];
        for (int i = 0; i < rows; i++) {
            rowWithIndex[i][0] = rowSum[i];
            rowWithIndex[i][1] = i;
        }
        for (int i = 0; i < cols; i++) {
            colWithIndex[i][0] = colSum[i];
            colWithIndex[i][1] = i;
        }
        sortWithIndex(rowWithIndex);
        sortWithIndex(colWithIndex);
        int i = 0, j = 0;
        while (i < rows && j < cols) {
            int currVal = Math.min(rowWithIndex[i][0], colWithIndex[j][0]);
            int rowIdx = rowWithIndex[i][1], colIdx = colWithIndex[j][1];
            result[rowIdx][colIdx] = currVal;
            rowWithIndex[i][0] -= currVal;
            colWithIndex[j][0] -= currVal;
            if (rowWithIndex[i][0] == 0) {
                i += 1;
            }
            if (colWithIndex[j][0] == 0) {
                j += 1;
            }
        }
        return result;
    }
    
    public void sortWithIndex(Integer[][] arr) {
        Arrays.sort(arr, new Comparator<Integer[]>() {
            @Override
            public int compare(Integer[] a, Integer[] b) {
                return a[0] - b[0];
            }
        });
    }
}