class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        int[] result = new int[2];
        for (int i = 0; i < n; i++) {
            if (nums[i] > 2 * n) {
                result[0] = i + 1;
            }
            if (nums[i] <= n) {
                result[1] = i + 1;
            }
        }
        return result;
    }
}