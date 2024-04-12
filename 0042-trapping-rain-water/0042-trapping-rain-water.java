class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int left = 0, right = n - 1, water = 0;
        int maxLeft = height[left];
        int maxRight = height[right];
        while (left < right) {
            if (height[left] <= height[right]) {
                left += 1;
                maxLeft = Math.max(maxLeft, height[left]);
                water += (maxLeft - height[left]);
            } else {
                right -= 1;
                maxRight = Math.max(maxRight, height[right]);
                water += (maxRight - height[right]);
            }
        }
        return water;
    }
}