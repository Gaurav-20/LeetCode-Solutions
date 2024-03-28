class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int left = 0, result = 0;
        for (int right = 0; right < nums.length; right++) {
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1);
            while (map.get(nums[right]) > k) {
                map.put(nums[left], map.get(nums[left]) - 1);
                left += 1;
            }
            result = Math.max(result, right - left + 1);
        }
        return result;
    }
}