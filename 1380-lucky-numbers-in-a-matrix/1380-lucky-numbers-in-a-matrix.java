class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int rows = matrix.length, cols = matrix[0].length;
        int[] minRows = new int[rows];
        int[] maxCols = new int[cols];
        Arrays.fill(minRows, Integer.MAX_VALUE);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                minRows[i] = Math.min(minRows[i], matrix[i][j]);
                maxCols[j] = Math.max(maxCols[j], matrix[i][j]);
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int curr = matrix[i][j];
                if (curr == minRows[i] && curr == maxCols[j]) {
                    result.add(curr);
                }
            }
        }
        return result;
    }
}