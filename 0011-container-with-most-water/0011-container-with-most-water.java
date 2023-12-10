class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1, result = 0;
        while (left < right) {
            int minHeight = Math.min(height[left], height[right]);
            result = Math.max(result, minHeight * (right - left));
            while (left < right && height[left] <= minHeight) {
                left++;
            }
            while (left < right && height[right] <= minHeight) {
                right--;
            }
        }
        return result;
    }
}