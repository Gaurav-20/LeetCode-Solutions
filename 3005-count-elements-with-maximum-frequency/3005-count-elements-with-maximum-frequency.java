class Solution {
    public int maxFrequencyElements(int[] nums) {
        int maxFreq = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], map.getOrDefault(nums[i], 0) + 1);
            maxFreq = Math.max(maxFreq, map.get(nums[i]));
        }
        int result = 0;
        for (Integer val : map.values()) {
            if (val == maxFreq) {
                result += 1;
            }
        }
        return result * maxFreq;
    }
}