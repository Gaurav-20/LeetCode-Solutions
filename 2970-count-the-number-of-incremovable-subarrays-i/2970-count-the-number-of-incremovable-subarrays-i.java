class Solution {
    public int incremovableSubarrayCount(int[] nums) {
        int n = nums.length, result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                boolean isIncreasing = true;
                for (int k = 1; k < i; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        isIncreasing = false;
                    }
                }
                if (j + 1 < n && i - 1 >= 0 && nums[j + 1] <= nums[i - 1]) {
                    isIncreasing = false;
                }
                for (int k = j + 2; k < n; k++) {
                    if (nums[k] <= nums[k - 1]) {
                        isIncreasing = false;
                    }
                }
                result += (isIncreasing == true) ? 1 : 0;
            }
        }
        return result;
    }
}