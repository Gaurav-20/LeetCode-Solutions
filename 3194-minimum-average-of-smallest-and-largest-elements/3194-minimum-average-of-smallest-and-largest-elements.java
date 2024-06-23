class Solution {
    public double minimumAverage(int[] nums) {
        Arrays.sort(nums);
        int left = 0, right = nums.length - 1;
        double result = Double.MAX_VALUE;
        while (left < right) {
            result = Math.min(result, (double) (nums[left] + nums[right]) / 2.0);
            left += 1;
            right -= 1;
        }
        return result;
    }
}