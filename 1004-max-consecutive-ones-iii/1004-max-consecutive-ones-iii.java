class Solution {
    public int longestOnes(int[] nums, int k) {
        int start = 0, end = 0, countOnes = 0, len = nums.length, res = 0;
        while (end < len) {
            if (nums[end] == 1) {
                countOnes++;
            }
            if (end - start + 1 - countOnes > k) {
                if (nums[start++] == 1) {
                    countOnes--;
                }
            }
            res = Math.max(res, end - start + 1);
            end++;
        }
        return res;
    }
}