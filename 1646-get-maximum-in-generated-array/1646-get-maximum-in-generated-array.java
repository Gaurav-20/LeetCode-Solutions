class Solution {
    public static int[] result;
    static {
        result = new int[101];
        result[1] = 1;
        for (int i = 2; i <= 100; i++) {
            int it = i / 2;
            if (i % 2 == 0) {
                result[i] = result[it];
            } else {
                result[i] = result[it] + result[it + 1];
            }
        }
        for (int i = 1; i <= 100; i++) {
            result[i] = Math.max(result[i], result[i - 1]);
        }
    }
    
    public int getMaximumGenerated(int n) {
        return result[n];
    }
}