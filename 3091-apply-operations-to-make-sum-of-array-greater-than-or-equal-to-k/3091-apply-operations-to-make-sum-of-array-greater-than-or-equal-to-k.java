class Solution {
    public int minOperations(int k) {
        int result = k;
        for (int i = 0; i < k; i++) {
            int curr = (k % (i + 1) == 0) ? k / (i + 1) : k / (i + 1) + 1;
            result = Math.min(result, curr + i - 1);
        }
        return result;
    }
}