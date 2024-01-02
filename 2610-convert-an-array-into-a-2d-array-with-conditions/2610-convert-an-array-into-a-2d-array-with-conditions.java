class Solution {
    public List<List<Integer>> findMatrix(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int maxRows = 0;
        for (int i = 0; i < nums.length; i++) {
            if (map.get(nums[i]) == null) {
                map.put(nums[i], 1);
            } else {
                map.put(nums[i], map.get(nums[i]) + 1);
            }
            maxRows = Math.max(maxRows, map.get(nums[i]));
        }
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < maxRows; i++) {
            result.add(new ArrayList<>());
        }
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            for (int i = 0; i < entry.getValue(); i++) {
                result.get(i).add(entry.getKey());
            }
        }
        return result;
    }
}