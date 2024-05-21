class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        Set<List<Integer>> setOfSubsets = new HashSet<>();
        for (int i = 0; i < (1 << nums.length); i++) {
            List<Integer> subset = new ArrayList<>();
            for (int j = 0; j < nums.length; j++) {
                if (((i >> j) & 1) == 1) {
                    subset.add(nums[j]);
                }
            }
            setOfSubsets.add(subset);
        }
        return new ArrayList<>(setOfSubsets);
    }
}