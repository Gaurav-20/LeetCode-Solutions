class Solution {
    public int countKDifference(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap<>();
        int result = 0;
        for (int num : nums) {
            result += map.getOrDefault(num + k, 0) + map.getOrDefault(num - k, 0);
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        return result;
    }
}