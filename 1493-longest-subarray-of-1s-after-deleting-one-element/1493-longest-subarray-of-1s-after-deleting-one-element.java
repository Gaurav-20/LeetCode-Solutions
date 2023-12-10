class Solution {
    public int longestSubarray(int[] nums) {
        int start = 0, end = 0, zeros = 0, len = nums.length, result = 0;
        while (end < len) {
            if (nums[end] == 0) {
                zeros++;
            }
            while (zeros > 1) {
                if (nums[start] == 0) {
                    zeros--;
                }
                start++;
            }
            result = Math.max(result, end - start + 1 - zeros);
            end++;
        }
        return (result == len) ? result - 1 : result;
    }
}