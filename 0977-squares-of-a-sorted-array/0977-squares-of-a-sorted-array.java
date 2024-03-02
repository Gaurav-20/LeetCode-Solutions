class Solution {
    public int[] sortedSquares(int[] nums) {
        int i = 0, j = nums.length - 1, iter = nums.length - 1;
        int[] result = new int[nums.length];
        while (i <= j) {
            int left = nums[i] * nums[i];
            int right = nums[j] * nums[j];
            if (left >= right) {
                result[iter] = left;
                i++;
            } else {
                result[iter] = right;
                j--;
            }
            iter--;
        }
        return result;
    }
}