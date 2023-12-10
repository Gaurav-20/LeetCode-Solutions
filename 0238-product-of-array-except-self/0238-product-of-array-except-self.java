class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int fromLeft = 1;
        int fromRight = 1;
        for (int i = 0; i < n; i++) {
            result[i] = 1;
            result[i] *= fromLeft;
            fromLeft *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= fromRight;
            fromRight *= nums[i];
        }
        return result;
    }
}