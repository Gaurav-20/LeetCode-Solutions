class Solution {
    public int findPairs(int[] nums, int k) {
        int result = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }
        for (Integer key : map.keySet()) {
            map.put(key, map.get(key) - 1);
            int diff = key + k;
            if (map.getOrDefault(diff, 0) > 0) {
                result += 1;
            }
            map.put(key, map.get(key) + 1);
        }
        return result;
    }
}