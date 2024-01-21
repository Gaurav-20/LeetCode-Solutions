class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.max(nums[0], nums[1]);
        }
        int lastToLast = nums[0];
        int last = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int curr = Math.max(last, lastToLast + nums[i]);
            lastToLast = last;
            last = curr;
        }
        return last;
    }
}