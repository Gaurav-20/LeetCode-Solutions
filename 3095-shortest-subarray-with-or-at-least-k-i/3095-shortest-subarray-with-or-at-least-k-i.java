class Solution {
    public int minimumSubarrayLength(int[] nums, int k) {
        int result = nums.length + 1;
        for (int i = 0; i < nums.length; i++) {
            int or = 0;
            for (int j = i; j < nums.length; j++) {
                or |= nums[j];
                if (or >= k) {
                    result = Math.min(result, j - i + 1);
                }
            }
        }
        return (result == nums.length + 1) ? -1 : result;
    }
}