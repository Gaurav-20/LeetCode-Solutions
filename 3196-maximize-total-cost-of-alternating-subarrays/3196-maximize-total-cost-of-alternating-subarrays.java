class Solution {
    public long maximumTotalCost(int[] nums) {
        int n = nums.length;
        long prev0 = nums[0];
        long prev1 = nums[0];
        for (int i = 1; i < n; i++) {
            long curr0 = Math.max(prev0, prev1) + nums[i];
            long curr1 = prev0 - nums[i];
            prev0 = curr0;
            prev1 = curr1;
        }
        return Math.max(prev0, prev1);
    }
}