class Solution {
    public int minOperations(int[] nums) {
        int result = 0;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i - 2] == 0) {
                nums[i - 2] = 1;
                nums[i - 1] = 1 - nums[i - 1];
                nums[i] = 1 - nums[i];
                result += 1;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }
        return result;
    }
}