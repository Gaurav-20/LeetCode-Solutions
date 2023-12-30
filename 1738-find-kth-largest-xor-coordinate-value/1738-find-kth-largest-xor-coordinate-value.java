class Solution {
    public int kthLargestValue(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length;
        int[][] xorMatrix = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    xorMatrix[i][j] = matrix[i][j];
                } else if (i == 0) {
                    xorMatrix[i][j] = matrix[i][j] ^ xorMatrix[i][j - 1];
                } else if (j == 0) {
                    xorMatrix[i][j] = matrix[i][j] ^ xorMatrix[i - 1][j];
                } else {
                    xorMatrix[i][j] = matrix[i][j] ^
                        xorMatrix[i - 1][j] ^ xorMatrix[i][j - 1] ^ xorMatrix[i - 1][j - 1];
                }
            }
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.offer(xorMatrix[i][j]);
                if (pq.size() > k) {
                    pq.poll();
                }
            }
        }
        return pq.peek();
    }
}