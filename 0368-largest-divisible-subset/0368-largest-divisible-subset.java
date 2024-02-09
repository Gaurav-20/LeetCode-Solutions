class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length, maxIdx = 0;
        int[] dp = new int[n];
        int[] pred = new int[n];
        Arrays.fill(dp, 1);
        Arrays.fill(pred, -1);
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pred[i] = j;
                }
            }
            if (dp[i] > dp[maxIdx]) {
                maxIdx = i;
            }
        }
        List<Integer> result = new ArrayList<>();
        for ( ; maxIdx >= 0; maxIdx = pred[maxIdx]) {
            result.add(nums[maxIdx]);
        }
        return result;
    }
}