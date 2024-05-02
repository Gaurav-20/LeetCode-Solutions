class Solution {
    public int findMaxK(int[] nums) {
        int result = -1;
        Set<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.contains(-num)) {
                result = Math.max(result, Math.abs(num));
            }
            set.add(num);
        }
        return result;
    }
}