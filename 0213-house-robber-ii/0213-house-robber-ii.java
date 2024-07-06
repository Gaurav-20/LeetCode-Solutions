class Solution {
    public int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        if (nums.length == 2) {
            return Math.max(nums[0], nums[1]);
        }
        return Math.max(solve(nums, 1, nums.length), solve(nums, 0, nums.length - 1));
    }
    
    public int solve(int[] nums, int low, int high) {
        int prev = 0, prevToPrev = 0, curr = 0;
        for (int i = low; i < high; i++) {
            curr = Math.max(prev, prevToPrev + nums[i]);
            prevToPrev = prev;
            prev = curr;
        }
        return curr;
    }
}