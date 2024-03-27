class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int left = 0;
        int windowProduct = 1;
        int result = 0;
        for (int right = 0; right < nums.length; right++) {
            windowProduct *= nums[right];
            while (windowProduct >= k) {
                windowProduct /= nums[left];
                left++;
            }
            result += right - left + 1; 
        }
        return result;
    }
}