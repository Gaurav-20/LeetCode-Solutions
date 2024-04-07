class Solution {
    public int longestMonotonicSubarray(int[] nums) {
        int result = 1;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                boolean isIncreasing = true, isDecreasing = true;
                int prev = nums[i];
                for (int k = i + 1; k <= j; k++) {
                    if (nums[k] <= prev) {
                        isIncreasing = false;
                    }
                    if (nums[k] >= prev) {
                        isDecreasing = false;
                    }
                    prev = nums[k];
                }
                if (isIncreasing || isDecreasing) {
                    result = Math.max(result, j - i + 1);
                }
            }
        }
        return result;
    }
}