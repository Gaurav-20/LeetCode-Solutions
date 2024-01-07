class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer>[] dp = new HashMap[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new HashMap<>();
        }
        int result = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diffL = (long) nums[i] - nums[j];
                if (diffL < Integer.MIN_VALUE || diffL > Integer.MAX_VALUE) {
                    continue;
                }
                int diff = (int) diffL;
                dp[i].put(diff, dp[i].getOrDefault(diff, 0) + 1);
                if (dp[j].containsKey(diff)) {
                    dp[i].put(diff, dp[i].get(diff) + dp[j].get(diff));
                    result += dp[j].get(diff);
                }
            }
        }
        return result;
    }
}