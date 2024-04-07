class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) {
        int n = nums.length;
        long result = 0;
        Arrays.sort(nums);
        int medianElement = nums[n / 2];
        nums[n / 2] = k;
        result += Math.abs(k - medianElement);
        for (int i = n / 2 - 1; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) {
                break;
            } else {
                result += Math.abs(nums[i] - nums[i + 1]);
                nums[i] = nums[i + 1];
            }
        }
        for (int i = n / 2 + 1; i < n; i++) {
            if (nums[i] >= nums[i - 1]) {
                break;
            } else {
                result += Math.abs(nums[i] - nums[i - 1]);
                nums[i] = nums[i - 1];
            }
        }
        return result;
    }
}