class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        long result = 0;
        for (int i = 0; i < n; i++) {
            result += dp[i];
        }
        return result;
    }
}