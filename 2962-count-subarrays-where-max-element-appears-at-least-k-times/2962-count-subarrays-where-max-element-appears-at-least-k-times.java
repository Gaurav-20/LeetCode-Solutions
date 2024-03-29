class Solution {
    public long countSubarrays(int[] nums, int k) {
        int maxElement = Integer.MIN_VALUE;
        for (int num : nums) {
            maxElement = Math.max(maxElement, num);
        }
        int maxElementCount = 0, left = 0, right = 0;
        long result = 0;
        while (right < nums.length) {
            if (maxElement == nums[(int) right++]) {
                maxElementCount++;
            }
            while (maxElementCount == k) {
                if (maxElement == nums[(int) left++]) {
                    maxElementCount--;
                }
            }
            result += left;
        }
        return result;
    }
}