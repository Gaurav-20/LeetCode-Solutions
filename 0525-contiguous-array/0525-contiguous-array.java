class Solution {
    public int findMaxLength(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }
        int result = findMaxSubarrayWithSumK(nums, 0);
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == -1) {
                nums[i] = 0;
            }
        }
        return result;
    }

    public int findMaxSubarrayWithSumK(int[] nums, int k) {
        int sum = 0, maxLen = 0, len = nums.length;
        Map<Integer, Integer> hash = new HashMap<>(); // key = sum, value = index
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            if (sum == k) {
                maxLen = i + 1;
            }
            if (hash.get(sum) == null) {
                hash.put(sum, i);
            }
            if (hash.get(sum - k) != null) {
                maxLen = Math.max(maxLen, i - hash.get(sum - k));
            }
        }
        return maxLen;
    }
}