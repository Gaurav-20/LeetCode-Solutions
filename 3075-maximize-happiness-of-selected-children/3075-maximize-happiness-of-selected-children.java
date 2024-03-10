class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        int decrementBy = 0, len = happiness.length;
        long result = 0;
        Arrays.sort(happiness);
        for (int i = len - 1; i >= len - k; i--) {
            result += Math.max(happiness[i] - decrementBy, 0l);
            decrementBy += 1;
        }
        return result;
    }
}