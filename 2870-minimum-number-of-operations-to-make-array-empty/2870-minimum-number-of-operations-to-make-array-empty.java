class Solution {
    public int minOperations(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (freq.get(nums[i]) == null) {
                freq.put(nums[i], 1);
            } else {
                freq.put(nums[i], freq.get(nums[i]) + 1);
            }
        }
        int result = 0;
        for (Integer count : freq.values()) {
            if (count == 1) {
                return -1;
            }
            int mod = count % 3;
            if (mod == 0) {
                result += (count / 3);
            } else if (mod == 1) {
                result += (count - 4) / 3 + 2;
            } else {
                result += (count - 2) / 3 + 1;
            }
        }
        return result;
    }
}